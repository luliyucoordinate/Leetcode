#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0050-Pow(x,n)/0050.cpp"

TEST(test, test1)
{
    ASSERT_EQ(1024.00000, Solution().myPow(2.00000, 10));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
