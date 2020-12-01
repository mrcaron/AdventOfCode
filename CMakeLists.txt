cmake_minimum_required(VERSION 3.18)

set(PROJ_NAME "hello_world")

project(${PROJ_NAME})

set(SRC_DIR "src")
set(CMAKE_CXX_STANDARD 14)

include_directories(${SRC_DIR})
add_executable(app ${SRC_DIR}/main.cpp)
target_link_libraries(app)
