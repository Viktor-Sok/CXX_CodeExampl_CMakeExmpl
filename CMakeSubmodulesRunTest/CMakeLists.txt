cmake_minimum_required(VERSION 3.22)
#set(CMAKE_C_COMPILER "C:/Dev/mingw64_winlibs/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "C:/Dev/mingw64_winlibs/bin/g++.exe")
#set(CMAKE_GENERATOR "MinGW Makefiles")
project(test VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRCS src/*)
#file(GLOB_RECURSE HDRS src/*.cpp)
#file(GLOB_RECURSE HDRS include/*.h)
add_executable(
${PROJECT_NAME} ${SRCS}
)
#include_directories(".")
#include_directories(${PROJECT_SOURCE_DIR}/test1)
add_subdirectory(test1)
