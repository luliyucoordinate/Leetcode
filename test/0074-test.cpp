#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0074-Search-a-2D-Matrix/0074.cpp"

TEST(test, test1)
{
    int target = 3;
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };
    ASSERT_EQ(true, Solution().searchMatrix(matrix, target));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
