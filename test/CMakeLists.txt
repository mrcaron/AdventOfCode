set(BINARY ${CMAKE_PROJECT_NAME}_tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include(GoogleTest)

include_directories(
    ../src
    ${GTEST_INCLUDE_DIRS}
)

add_executable(${BINARY} ${TEST_SOURCES})
target_link_libraries(${BINARY} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread ${CMAKE_PROJECT_NAME}_lib)

gtest_discover_tests(${BINARY})