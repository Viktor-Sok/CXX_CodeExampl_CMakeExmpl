cmake_minimum_required(VERSION 3.2)
project(main)
set(CMAKE_CXX_STANDARD 17)
set(SOURCES main.cpp fun.cpp)
set(HEADERS fun.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include(CTest) # CMake feature
enable_testing() # CMake feature must be before add_subdirectory(becouse it's recursive)
add_subdirectory(tests)
