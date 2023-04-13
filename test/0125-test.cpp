#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0125-Valid-Palindrome/0125.cpp"

TEST(test, test1)
{
    std::string s = "A man, a plan, a canal: Panama";
    ASSERT_EQ(true, Solution().isPalindrome(s));
}

TEST(test, test2)
{
    std::string s = "race a car";
    ASSERT_EQ(false, Solution().isPalindrome(s));
}

TEST(test, test3)
{
    std::string s = " ";
    ASSERT_EQ(true, Solution().isPalindrome(s));
}

TEST(test, test4)
{
    std::string s = "OP";
    ASSERT_EQ(false, Solution().isPalindrome(s));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
