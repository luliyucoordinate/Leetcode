#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0028-Implement-strStr()/0028.cpp"

TEST(test, test1)
{
    ASSERT_EQ(0, Solution().strStr("a", ""));
}

TEST(test, test2)
{
    ASSERT_EQ(-1, Solution().strStr("mississippi", "a"));
}

TEST(test, test3)
{
    ASSERT_EQ(0, Solution().strStr("a", "a"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
