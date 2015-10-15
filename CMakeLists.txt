cmake_minimum_required(VERSION 2.6)

project(mateLight)

string(COMPARE EQUAL ${CMAKE_CXX_COMPILER_ID} "Clang" is_clang)
if(is_clang)
    SET(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated-register")
    message(STATUS "Clang compiler")
endif(is_clang)

string(COMPARE EQUAL ${CMAKE_CXX_COMPILER_ID} "GNU" is_gnu)
if(is_gnu)
    SET(CMAKE_CXX_FLAGS -std=c++11)
    message(STATUS "GNU compiler")
endif(is_gnu)

add_subdirectory(lib)
add_subdirectory(test)

