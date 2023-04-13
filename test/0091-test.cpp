#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0091-Decode-Ways/0091.cpp"

TEST(test, test1)
{
    ASSERT_EQ(2, Solution().numDecodings("12"));
}

TEST(test, test2)
{
    ASSERT_EQ(1, Solution().numDecodings("10"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
