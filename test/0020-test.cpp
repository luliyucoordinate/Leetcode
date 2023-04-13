#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0020-Valid-Parentheses/0020.cpp"

TEST(test, test1)
{
    ASSERT_EQ(false, Solution().isValid("(]"));
}

TEST(test, test2)
{
    ASSERT_EQ(false, Solution().isValid("([)]"));
}

TEST(test, test3)
{
    ASSERT_EQ(true, Solution().isValid("()[]{}"));
}

TEST(test, test4)
{
    ASSERT_EQ(true, Solution().isValid("()"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
