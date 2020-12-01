set (SOURCES main.cpp add.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})