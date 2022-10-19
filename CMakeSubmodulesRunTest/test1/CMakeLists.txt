cmake_minimum_required(VERSION 3.22)
project(tests1 VERSION 1.0.0)

message(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

#include_directories(${PROJECT_SOURCE_DIR}/fun)
add_executable(${PROJECT_NAME} test1.cpp ${CMAKE_SOURCE_DIR}/src/fun.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
#target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src) 
#target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
enable_testing()
add_test(NAME tests1 COMMAND tests1)