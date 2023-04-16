#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0029-Divide-Two-Integers/0029.cpp"

TEST(test, test1)
{
    ASSERT_EQ(1, Solution().divide(4, 3));
}

TEST(test, test2)
{
    ASSERT_EQ(3, Solution().divide(10, 3));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
