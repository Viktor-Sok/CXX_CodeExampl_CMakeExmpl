#include <gtest/gtest.h>
#include <fun.h>



//TEST(TestSuiteName, TestName) 
// TestSuit group of related in some sense tests, which have different names
//--------------------TestFunctionSuite---------------------------//
TEST(TestFunctionFunSuite, handle_positives) {
//ASSERT_EQ(fun(3 ,4 ), 7);
    EXPECT_EQ(fun(3 ,4 ), 7) << "GOOOD test"; // will never be printed becouse this expect is correct
    EXPECT_EQ(fun(3 ,6 ), 4) << "DAAAAMMMNN test"; 
    EXPECT_EQ(fun(3 ,6 ), 8) << "ANOTHER DAAAAMMMNN test "; 
}
TEST(TestFunctionFunSuite1, handle_negatives) {
//ASSERT_EQ(fun(3 ,4 ), 7);
    ASSERT_EQ(fun(3 ,-6 ), 5) << "DAAAAMMMNN test"; 
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv); // let us recieve command line arguments for gtests and other free command line args
    return RUN_ALL_TESTS();
}

