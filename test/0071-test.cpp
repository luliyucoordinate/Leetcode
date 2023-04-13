#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0071-Simplify-Path/0071.cpp"

TEST(test, test1)
{
    ASSERT_EQ("/home", Solution().simplifyPath("/home/"));
}

TEST(test, test2)
{
    ASSERT_EQ("/c", Solution().simplifyPath("/a/./b/../../c/"));
}

TEST(test, test3)
{
    ASSERT_EQ("/a/b/c", Solution().simplifyPath("/a//b////c/d//././/.."));
}

TEST(test, test4)
{
    ASSERT_EQ("/", Solution().simplifyPath("/."));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
