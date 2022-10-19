cmake_minimum_required(VERSION 3.22)
project(libConnected VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
add_executable(
${PROJECT_NAME} main.cpp
)
# include headers fo static , so we can use them as API and VScode (or other IDE) generates autocompletion
# based on it
target_include_directories(${PROJECT_NAME} PUBLIC mylib/inc )
# defines what library we want to link
target_link_libraries(${PROJECT_NAME} sum_lib)
#  which folder to look for the library
target_link_directories(${PROJECT_NAME}  PUBLIC mylib)