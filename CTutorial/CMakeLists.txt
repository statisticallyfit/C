cmake_minimum_required(VERSION 3.2)
project(.)

#use
#   FOR C ==> set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")
#   FOR C++ ==> set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")

set(SOURCE_FILES bookKochan/chapter10_CharacterStrings/ex4_Substring.c)
add_executable(CTutorial ${SOURCE_FILES})
