CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(matelight)

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

ADD_LIBRARY(
  ml STATIC 
  frame.cpp
  ringbuffer.cpp
)

