#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0087-Scramble-String/0087.cpp"

TEST(test, test1)
{
    ASSERT_EQ(true, Solution().isScramble("great", "rgeat"));
}

TEST(test, test2)
{
    ASSERT_EQ(true, Solution().isScramble("great", "rgtae"));
}

TEST(test, test3)
{
    ASSERT_EQ(true, Solution().isScramble("abc", "bca"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
