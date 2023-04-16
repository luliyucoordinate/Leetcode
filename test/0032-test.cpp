#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0032-Longest-Valid-Parentheses/0032.cpp"

TEST(test, test1)
{
    ASSERT_EQ(2, Solution().longestValidParentheses("(()"));
}
TEST(test, test2)
{
    ASSERT_EQ(2, Solution().longestValidParentheses("()(()"));
}
TEST(test, test3)
{
    ASSERT_EQ(4, Solution().longestValidParentheses("(())("));
}
TEST(test, test4)
{
    ASSERT_EQ(6, Solution().longestValidParentheses("()(())"));
}

TEST(test, test5)
{
    ASSERT_EQ(4, Solution().longestValidParentheses(")()())"));
}

TEST(test, test6)
{
    ASSERT_EQ(4, Solution().longestValidParentheses(")()())()()("));
}

TEST(test, test7)
{
    ASSERT_EQ(8, Solution().longestValidParentheses("((())())"));
}

TEST(test, test8)
{
    ASSERT_EQ(10, Solution().longestValidParentheses(")()(((())))("));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
