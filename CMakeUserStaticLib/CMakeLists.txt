cmake_minimum_required(VERSION 3.22)
#set(CMAKE_C_COMPILER "C:/Dev/mingw64_winlibs/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "C:/Dev/mingw64_winlibs/bin/g++.exe")
#set(CMAKE_GENERATOR "MinGW Makefiles")
project(main VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS include/*.h)
# you have to inlcude both .cpp and .h files to add_executable
add_executable(
${PROJECT_NAME} ${SRCS} ${HDRS}
)
# used for resolving issues with #include "file.h", so we don't need to write #include "../include/file.h"
# API of our library (headers) fun.h is also included here
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/lib/inc)
# subdirectory where we build library
add_subdirectory(lib)
# linking aour static libraty to the project
target_link_libraries(${PROJECT_NAME} sum_lib)
