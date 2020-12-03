set (SOURCES main.cpp add.cpp)

set(CMAKE_CXX_CPPCHECK "cppcheck")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -o3")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
