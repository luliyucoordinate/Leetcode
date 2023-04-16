#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0121-Best-Time-to-Buy-and-Sell-Stock/0121.cpp"

TEST(test, test1)
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    ASSERT_EQ(5, Solution().maxProfit(prices));
}

TEST(test, test2)
{
    std::vector<int> prices = {7, 6, 4, 3, 1};
    ASSERT_EQ(0, Solution().maxProfit(prices));
}

TEST(test, test3)
{
    std::vector<int> prices = {2, 4, 1};
    ASSERT_EQ(1, Solution().maxProfit(prices));
}

TEST(test, test4)
{
    std::vector<int> prices = {1, 2};
    ASSERT_EQ(1, Solution().maxProfit(prices));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
