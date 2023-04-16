#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0076-Minimum-Window-Substring/0076.cpp"

TEST(test, test1)
{
    std::string expected = "BANC";
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    ASSERT_EQ(expected, Solution().minWindow(s, t));
}

TEST(test, test2)
{
    std::string expected = "";
    std::string s = "A";
    std::string t = "B";
    ASSERT_EQ(expected, Solution().minWindow(s, t));
}

TEST(test, test3)
{
    std::string expected = "cwae";
    std::string s = "cabwefgewcwaefgcf";
    std::string t = "cae";
    ASSERT_EQ(expected, Solution().minWindow(s, t));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
