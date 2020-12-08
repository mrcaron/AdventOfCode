#sets the version of CMAke that I'm wanting to use
cmake_minimum_required(VERSION 3.18)

#set up a variable to hold the project name
set(PROJ_NAME "ReportRepair"
    CACHE STRING "sets up the project name")

#declare a new project
project(${PROJ_NAME})

#tell Cmake that when looking for a compiler, use one that conforms to CPP14
set(CMAKE_CXX_STANDARD 14
    CACHE STRING "flags for CPP 14 standard")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#enable unit testing
include(CTest)

#add_subdirectory pulls in any CMakeFiles contained therein

add_subdirectory(src)

if (BUILD_TESTING)
    
    # Build GTest
    set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)
    set (INSTALL_GTEST OFF
         CACHE STRING "Turning off GTest Install")

    add_subdirectory(third_party/googletest)
    target_compile_definitions(gtest
        PUBLIC
            GTEST_LANG_CXX20
            GTEST_HAS_TR1_TUPLE=0
    )

    # SET GTEST VARS
    set (GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include)
    set (GTEST_LIBRARIES ${CMAKE_BINARY_DIR}/lib/libgtest.a
         CACHE STRING "Setting GTest library")
    set (GTEST_MAIN_LIBRARIES ${CMAKE_BINARY_DIR}/lib/libgtest_main.a
         CACHE STRING "Setting GTest Main library")
    set (GTEST_BOTH_LIBRARIES ${CMAKE_BINARY_DIR}/lib/libgtest.a ${CMAKE_BINARY_DIR}/lib/libgtest_main.a
         CACHE STRING "Setting GTest Main library")

    # SET GMOCK VARS
    set (GMOCK_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/third_party/googletest/googlemock/include)
    set (GMOCK_LIBRARIES ${CMAKE_BINARY_DIR}/lib/libgmock.a
         CACHE STRING "Setting GMock library")
   

    add_subdirectory(test)
endif()

