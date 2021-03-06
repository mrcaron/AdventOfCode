#making the test executable name a variable
set(BINARY tests)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

####################################################################################################################
# DEPENDENCIES
####################################################################################################################

#include the GoogleTest module, which allows you to search for tests using gtest_discover_tests
include(GoogleTest)

# CPP Check
#find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
#set(CMAKE_CXX_CPPCHECK "cppcheck")
#if (CMAKE_CXX_CPPCHECK)
#    list(
#        APPEND CMAKE_CXX_CPPCHECK
#            "--enable=warning"
#            "--inconclusive"
#            "--force"
#            "--inline-suppr"
#            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
#    )
#endif()

####################################################################################################################

####################################################################################################################
# BUILDING TEST EXECUTABLE
####################################################################################################################
#include direcctory search path inclusinos
include_directories(
    ../src
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

#recursively search through this directory and put all things *.h, *.cpp in a variable called "TEST_SOURCES"
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES 
    ../src/SumFinder.cpp
    ../src/PasswordVerifier.cpp
    ../src/TreeDetector.cpp
    ../src/PassportVerifier.cpp
    ../src/BoardingPass.cpp
)

add_executable(${BINARY})
target_sources(${BINARY}
    PRIVATE
        ${TEST_SOURCES} 
        ${SOURCES}
)
set_target_properties(${BINARY} PROPERTIES COMPILE_FLAGS "${cxx_strict}")

#link it against the originally built product as well as the google libraries
target_link_libraries(${BINARY} gtest)
target_link_libraries(${BINARY} gmock)
target_link_libraries(${BINARY} pthread)
target_link_libraries(${BINARY} -fprofile-arcs)
####################################################################################################################

####################################################################################################################
# SETUP Code Coverage
####################################################################################################################
include(CodeCoverage)

append_coverage_compiler_flags()

# Optimization flags
# -O0 = no optimization
# -Wall = turn on all warnings
set(CMAKE_CXX_FLAGS "-g -O0 -Wall --coverage")

setup_target_for_coverage_gcovr_xml(
    NAME coverage
    EXECUTABLE ${BINARY} --gtest_output=xml:${CMAKE_BINARY_DIR}/test_report.xml
    BASE_DIR ${PROJECT_SOURCE_DIR}/src
    EXCLUDE ${PROJECT_SOURCE_DIR}/test)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)
####################################################################################################################

####################################################################################################################
# Locate and enumerate tests for running in CTest
####################################################################################################################
if (BUILD_TESTING)
    gtest_discover_tests(${BINARY})
endif()