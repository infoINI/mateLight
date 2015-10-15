CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(matelight)

ADD_LIBRARY(
  ml STATIC 
  frame.cpp
  ringbuffer.cpp
)

