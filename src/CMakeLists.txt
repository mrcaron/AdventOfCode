set (SOURCES main.cpp add.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

#need to create a library so that I can link the test app to it
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
