#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0063-Unique-Paths-II/0063.cpp"

TEST(test, test1)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {0, 0},
        {0, 1},
    };
    ASSERT_EQ(0, Solution().uniquePathsWithObstacles(obstacleGrid));
}

TEST(test, test2)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    ASSERT_EQ(2, Solution().uniquePathsWithObstacles(obstacleGrid));
}

TEST(test, test3)
{
    std::vector<std::vector<int>> obstacleGrid = {
        {1, 0}};
    ASSERT_EQ(0, Solution().uniquePathsWithObstacles(obstacleGrid));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
