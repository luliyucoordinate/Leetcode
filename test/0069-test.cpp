#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0069-Sqrt(x)/0069.cpp"

TEST(test, test1)
{
    ASSERT_EQ(4, Solution().mySqrt(16));
}

TEST(test, test2)
{
    ASSERT_EQ(2, Solution().mySqrt(8));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
