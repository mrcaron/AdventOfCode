cmake_minimum_required(VERSION 2.4)

set(PROJ_NAME "hello_world")

project(${PROJ_NAME})

set(SRC_DIR "src")
set(CMAKE_CXX_STANDARD 14)

include_directories(${SRC_DIR})
add_executable(app ${SRC_DIR}/main.cpp)
target_link_libraries(app)
