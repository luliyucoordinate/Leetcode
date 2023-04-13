#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0003-Longest-Substring-Without-Repeating-Characters/0003.cpp"

TEST(test, test1)
{
    int expected = 3;
    std::string s = "abcabcbb";

    ASSERT_EQ(expected, Solution().lengthOfLongestSubstring(s));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
