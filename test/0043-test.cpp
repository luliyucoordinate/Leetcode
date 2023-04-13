#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0043-Multiply-Strings/0043.cpp"

TEST(test, test1)
{
    std::string num1 = "123";
    std::string num2 = "45";
    std::string expected = "5535";
    ASSERT_EQ(expected, Solution().multiply(num1, num2));
}

TEST(test, test2)
{
    std::string num1 = "9133";
    std::string num2 = "0";
    std::string expected = "0";
    ASSERT_EQ(expected, Solution().multiply(num1, num2));
}

TEST(test, test3)
{
    std::string num1 = "6913259244";
    std::string num2 = "71103343";
    std::string expected = "491555843274052692";
    ASSERT_EQ(expected, Solution().multiply(num1, num2));
}

TEST(test, test4)
{
    std::string num1 = "401716832807512840963";
    std::string num2 = "167141802233061013023557397451289113296441069";
    std::string expected = "67143675422804947379429215144664313370120390398055713625298709447";
    ASSERT_EQ(expected, Solution().multiply(num1, num2));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
