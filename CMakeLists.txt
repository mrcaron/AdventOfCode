cmake_minimum_required(VERSION 3.18)

set(PROJ_NAME "ReportRepair")

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)