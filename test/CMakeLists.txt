#making the test executable name a variable
set(BINARY ${CMAKE_PROJECT_NAME}_tests)

#recursively search through this directory and put all things *.h, *.cpp in a variable called "TEST_SOURCES"
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

#locate the GTest libraries (must be first installed!)
find_package(GTest REQUIRED)
#locate the Threads libraries (must be installed!)
find_package(Threads REQUIRED)

#include the GoogleTest module, which allows you to search for tests using gtest_discover_tests
include(GoogleTest)

#include direcctory search path inclusinos
include_directories(
    ../src
    ${GTEST_INCLUDE_DIRS}
)

#create a new test executable
add_executable(${BINARY} ${TEST_SOURCES})

#link it against the originally built product as well as the google libraries
target_link_libraries(${BINARY} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread ${CMAKE_PROJECT_NAME}_lib)

enable_testing()
gtest_discover_tests(${BINARY})
