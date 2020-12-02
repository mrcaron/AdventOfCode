#sets the version of CMAke that I'm wanting to use
cmake_minimum_required(VERSION 3.18)

#set up a variable to hold the project name
set(PROJ_NAME "ReportRepair")

#declare a new project
project(${PROJ_NAME})

#tell Cmake that when looking for a compiler, use one that conforms to CPP14
set(CMAKE_CXX_STANDARD 14)

# supporting code coverage (see all of them @ https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html#Option-Index)
# -O0 = no optimization
# -Wall = turn on all warnings
# --coverage = compile and link for code coverage analysis
set(CMAKE_CXX_FLAGS "-g -O0 -Wall --coverage")

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/RunAdder.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

#make sure all the things use headers in src/
include_directories(src)

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
# adds a custom command to the gcov target; see https://cmake.org/cmake/help/latest/command/add_custom_command.html#build-events
# it will run AFTER the gcov target instructions
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${OBJECT_DIR}
        | grep -A 5 "Adder.cpp" > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage  # Need separate command for this line
    )

# Create the gcov-clean target. This cleans the build as well as generated 
# .gcda and .gcno files.
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    
# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

#add_subdirectory pulls in any CMakeFiles contained theirin
add_subdirectory(src bin)
add_subdirectory(test test_bin)
