#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0097-Interleaving-String/0097.cpp"

TEST(test, test1)
{
    ASSERT_EQ(true, Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac"));
}

TEST(test, test2)
{
    ASSERT_EQ(false, Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
