#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0007-Reverse-Integer/0007.cpp"

TEST(test, test1)
{
    ASSERT_EQ(0, Solution().reverse(1534236469));
}

TEST(test, test2)
{
    ASSERT_EQ(-123, Solution().reverse(-321));
}


GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
