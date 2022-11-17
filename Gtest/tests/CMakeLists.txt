cmake_minimum_required(VERSION 3.2)
project(mytests)
set(CMAKE_CXX_STANDARD 17)

# Getting Gtest Framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Headers/Source files in which we want to test function/method/class
set(SOURCES fun_test.cpp ../fun.cpp)
set(HEADERS ../fun.h)
set(SOURCES1 fun_test1.cpp ../fun.cpp)
set(HEADERS1 ../fun.h)
# Exetcutable which runs the tests
link_libraries(GTest::gtest_main) # instead of using two lines of target_link_libraries for two executables
include_directories("../") # instead of using two lines of target_include_directories for two executables
# Copying testcases to the build directory to access them when testing
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/testdata
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/testdata/)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_executable(${PROJECT_NAME}_1 ${SOURCES1} ${HEADERS1})
# Directories to find headers of the program we want to test
# It's used in order to write in .cpp file #include <.h> instead of "../.some_path./.h"

#target_include_directories(${PROJECT_NAME} PUBLIC "../")
#target_include_directories(${PROJECT_NAME}_1 PUBLIC "../")
# linking Gtest library to our test executable

#target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
#target_link_libraries(${PROJECT_NAME}_1 GTest::gtest_main)

# allows CMake to run test by command in command line in build directory $ctest
include(GoogleTest)
#gtest_discover_tests(${PROJECT_NAME}) 
# we can add several tests executables
add_test(NAME ${PROJECT_NAME}  COMMAND ${PROJECT_NAME} )
add_test(NAME ${PROJECT_NAME}_1  COMMAND ${PROJECT_NAME}_1 )


