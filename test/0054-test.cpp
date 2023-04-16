#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/0054-Spiral-Matrix/0054.cpp"

TEST(test, test1)
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<int> nums = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    ASSERT_EQ(nums, Solution().spiralOrder(matrix));
}

TEST(test, test2)
{
    std::vector<std::vector<int>> matrix = {};
    ASSERT_EQ(std::vector<int>({}), Solution().spiralOrder(matrix));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
