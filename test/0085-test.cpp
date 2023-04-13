#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0085-Maximal-Rectangle/0085.cpp"

TEST(test, test1)
{
    std::vector<std::vector<char>> board = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    ASSERT_EQ(6, Solution().maximalRectangle(board));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
