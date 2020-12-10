set (SOURCES_AOC1 
    Aoc1_Main.cpp 
    SumFinder.cpp
)

set (SOURCES_AOC2 
    Aoc2_Main.cpp 
    PasswordVerifier.cpp
)

# Current make target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc2 ${SOURCES_AOC2})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc1 ${SOURCES_AOC1})


# disabling cppcheck for now
#set(CMAKE_CXX_CPPCHECK "cppcheck")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -o3")
