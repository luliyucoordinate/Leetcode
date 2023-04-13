#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0120-Triangle/0120.cpp"

TEST(test, test1)
{
    std::vector<std::vector<int>> triangle = {};

    triangle.push_back(std::vector<int>({1}));
    triangle.push_back(std::vector<int>({2, 3}));
    ASSERT_EQ(3, Solution().minimumTotal(triangle));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
