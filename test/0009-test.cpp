#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0009-Palindrome-Number/0009.cpp"

TEST(test, test1)
{
    ASSERT_EQ(false, Solution().isPalindrome(2147483647));
}

TEST(test, test2)
{
    ASSERT_EQ(true, Solution().isPalindrome(0));
}

TEST(test, test3)
{
    ASSERT_EQ(true, Solution().isPalindrome(1));
}

TEST(test, test4)
{
    ASSERT_EQ(false, Solution().isPalindrome(10));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
