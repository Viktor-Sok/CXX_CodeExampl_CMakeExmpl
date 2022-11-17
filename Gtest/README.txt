1. CTest is a Cmake built-in test runner
include(CTest)
enable_testing() #must be before add_subdirectory becouse it's recursive for all subprojects
add_subdirectory(tests1)

In child CMakeLists
add_executable(test1 ...)
add_executable(test2 ...)
# each test is the executable
add_test(NAME test1 COMMAND test1)
add_test(NAME test2 COMMAND test2)

2.
There are two ways to run the tests:
i). Using Cmake support for gtest (specified in CMakeLists.txt)
After compiling and building project and tests for it (two executables),
in the build folder type:
	$ctest
	$ctest -V // verbose output
The log of test results will be saved in Testing folder,
it will be contain the same information which you can get in
the console using test runnig method mentioned below

ii). Directly running executable with tests, in build folder
	$mytests.exe
	 
3. ASSERT_EQ, EXPECT_EQ - teh difference is EXPECT_EQ will runt all the assertion in the testsuit, but ASSERT_EQ will stop 
at the first failed test, usually it's better to use EXPECT_EQ to see all the failures 

4. ::testing::InitGoogleTest(&argc, argv); is neccesary only if you want to pass arguments to your test program
List all available tests
$mytests --gtest_list_tests
Run specific TestSuite (regex * is used)
$mytests --gtest_filter=TestFunctionFunSuite.*
5. Links
https://habr.com/ru/post/119090/