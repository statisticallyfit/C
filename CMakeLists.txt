cmake_minimum_required(VERSION 3.2)
project(CTutorial)

#use
#   FOR C ==> set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")
#   FOR C++ ==> set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")

set(SOURCE_FILES CTutorial/book/chapter8_Functions/ex8_Quadratic.c)
add_executable(CTutorial ${SOURCE_FILES})
