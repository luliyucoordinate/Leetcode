#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0052-N-Queens-II/0052.cpp"

TEST(test, test1)
{
    ASSERT_EQ(1, Solution().totalNQueens(1));
}

TEST(test, test2)
{
    ASSERT_EQ(92, Solution().totalNQueens(8));
}

TEST(test, test3)
{
    ASSERT_EQ(0, Solution().totalNQueens(2));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
