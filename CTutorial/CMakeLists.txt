cmake_minimum_required(VERSION 3.2)
project(CTutorial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES book/chapter5_Loops/ex11_sumOfDigits.cpp)
add_executable(CTutorial ${SOURCE_FILES})
