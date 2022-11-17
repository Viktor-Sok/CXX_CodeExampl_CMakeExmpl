#include <gtest/gtest.h>
#include <fun.h>
#include <fstream>
#include <string>

using namespace std;

//TEST(TestSuiteName, TestName) 
// TestSuit group of related in some sense tests, which have different names
//--------------------TestFunctionSuite---------------------------//
TEST(TestFunctionFunSuite, handle_positives) {
//ASSERT_EQ(fun(3 ,4 ), 7);
    ifstream f("testdata/test1/data.txt");
    if (!f.is_open()) 
        throw runtime_error("Problem with opening the file");
    int a, b, c, count = 0;
    while(f >> a >> b >> c) {
        if (!f.good())
            throw runtime_error("Problem with reading the file");
        EXPECT_EQ(fun(a, b), c) << "TEST FROM FILE " + to_string(count);
        ++count;

    }
    f.close();
}
