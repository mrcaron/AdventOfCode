set (SOURCES 
    main.cpp 
    SumFinder.cpp
    PasswordVerifier.cpp
)

# disabling cppcheck for now
#set(CMAKE_CXX_CPPCHECK "cppcheck")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -o3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
