set (SOURCES_AOC1 
    Aoc1_Main.cpp 
    SumFinder.cpp
)

set (SOURCES_AOC2 
    Aoc2_Main.cpp 
    PasswordVerifier.cpp
)

set (SOURCES_AOC3 
    Aoc3_Main.cpp
    TreeDetector.cpp
)

set (SOURCES_AOC4 
    Aoc4_Main.cpp
    PassportVerifier.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc4 ${SOURCES_AOC4})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc3 ${SOURCES_AOC3})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc2 ${SOURCES_AOC2})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(aoc1 ${SOURCES_AOC1})


# disabling cppcheck for now
#set(CMAKE_CXX_CPPCHECK "cppcheck")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -o3")
