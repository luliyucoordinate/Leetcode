#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0044-Wildcard-Matching/0044.cpp"

TEST(test, test1)
{
    ASSERT_EQ(false, Solution().isMatch("aa", "a"));
}

TEST(test, test2)
{
    ASSERT_EQ(true, Solution().isMatch("aa", "aa"));
}

TEST(test, test3)
{
    ASSERT_EQ(false, Solution().isMatch("aaa", "aa"));
}

TEST(test, test4)
{
    ASSERT_EQ(true, Solution().isMatch("aa", "*"));
}

TEST(test, test5)
{
    ASSERT_EQ(true, Solution().isMatch("aa", "a*"));
}

TEST(test, test6)
{
    ASSERT_EQ(true, Solution().isMatch("ab", "?*"));
}

TEST(test, test7)
{
    ASSERT_EQ(false, Solution().isMatch("aab", "c*a*b"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
