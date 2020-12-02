set (SOURCES main.cpp add.cpp)

set(CMAKE_CXX_CPPCHECK "cppcheck")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
