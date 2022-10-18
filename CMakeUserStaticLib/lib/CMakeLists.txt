cmake_minimum_required(VERSION 3.22)
project(sum_lib VERSION 1.0.0)

#message(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

#include_directories(${PROJECT_SOURCE_DIR}/fun)
add_library(${PROJECT_NAME} fun.cpp inc/fun.h)
# to resolve issues with #include "inc/dif.h" and instead writing "dif.h" in "dif.cpp"
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
#target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src) 
#target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
