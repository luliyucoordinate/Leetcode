#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0070-Climbing-Stairs/0070.cpp"

TEST(test, test1)
{
    ASSERT_EQ(3, Solution().climbStairs(3));
}

TEST(test, test2)
{
    ASSERT_EQ(13, Solution().climbStairs(6));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
