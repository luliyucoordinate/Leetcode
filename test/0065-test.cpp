#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0065-Valid-Number/0065.cpp"

TEST(test, test1)
{
    ASSERT_EQ(false, Solution().isNumber("1 a"));
}

TEST(test, test2)
{
    ASSERT_EQ(false, Solution().isNumber("4e+"));
}

TEST(test, test3)
{
    ASSERT_EQ(true, Solution().isNumber("005047e+6"));
}

TEST(test, test4)
{
    ASSERT_EQ(false, Solution().isNumber(".e10"));
}

TEST(test, test5)
{
    ASSERT_EQ(true, Solution().isNumber("2e10"));
}

TEST(test, test6)
{
    ASSERT_EQ(false, Solution().isNumber("abc"));
}

TEST(test, test7)
{
    ASSERT_EQ(false, Solution().isNumber(" -."));
}

TEST(test, test8)
{
    ASSERT_EQ(true, Solution().isNumber("+.8"));
}

TEST(test, test9)
{
    ASSERT_EQ(false, Solution().isNumber("."));
}

TEST(test, test10)
{
    ASSERT_EQ(false, Solution().isNumber(".e1"));
}

TEST(test, test11)
{
    ASSERT_EQ(true, Solution().isNumber("0"));
}

TEST(test, test12)
{
    ASSERT_EQ(false, Solution().isNumber("0e"));
}

TEST(test, test13)
{
    ASSERT_EQ(false, Solution().isNumber("6ee69"));
}

TEST(test, test14)
{
    ASSERT_EQ(false, Solution().isNumber("+++"));
}

TEST(test, test15)
{
    ASSERT_EQ(false, Solution().isNumber("0e"));
}

TEST(test, test16)
{
    ASSERT_EQ(false, Solution().isNumber("e9"));
}

TEST(test, test17)
{
    ASSERT_EQ(true, Solution().isNumber(" 0.1 "));
}

TEST(test, test18)
{
    ASSERT_EQ(true, Solution().isNumber("46.e3"));
}

TEST(test, test19)
{
    ASSERT_EQ(false, Solution().isNumber(".."));
}

TEST(test, test20)
{
    ASSERT_EQ(false, Solution().isNumber(".e1"));
}

TEST(test, test21)
{
    ASSERT_EQ(false, Solution().isNumber("1e."));
}

TEST(test, test22)
{
    ASSERT_EQ(true, Solution().isNumber("-1."));
}

TEST(test, test23)
{
    ASSERT_EQ(false, Solution().isNumber("6e6.5"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
