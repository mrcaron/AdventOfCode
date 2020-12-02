#sets the version of CMAke that I'm wanting to use
cmake_minimum_required(VERSION 3.18)

#set up a variable to hold the project name
set(PROJ_NAME "ReportRepair"
    CACHE STRING "sets up the project name")

#declare a new project
project(${PROJ_NAME})

#tell Cmake that when looking for a compiler, use one that conforms to CPP14
set(CMAKE_CXX_STANDARD 14
    CACHE STRING "flags for CPP 14 standard")

#enable unit testing
include(CTest)
#enable_testing()

#add_subdirectory pulls in any CMakeFiles contained theirin
add_subdirectory(src)
add_subdirectory(test)
