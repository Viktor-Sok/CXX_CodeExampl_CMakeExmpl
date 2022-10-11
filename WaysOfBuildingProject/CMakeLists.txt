cmake_minimum_required(VERSION 3.1)
project(cmakelists_test CXX)
set(CMAKE_CXX_STANDARD 14)

# saving executable in the "bin" folder of the project
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# build executable (it's also possible to build libray or archive)
add_executable(
cmakelists_test 
src/main.cpp 
src/merge_names.cpp 
src/friend.cpp 
)

# path to the headers files
target_include_directories(cmakelists_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
