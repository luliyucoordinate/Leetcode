#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0064-Minimum-Path-Sum/0064.cpp"

TEST(test, test1)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {1, 2},
        {1, 1}};
    ASSERT_EQ(3, Solution().minPathSum(obstacleGrid));
}

TEST(test, test2)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {1}};
    ASSERT_EQ(1, Solution().minPathSum(obstacleGrid));
}

TEST(test, test3)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    ASSERT_EQ(7, Solution().minPathSum(obstacleGrid));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
