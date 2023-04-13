#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0122-Best-Time-to-Buy-and-Sell-Stock-II/0122.cpp"

TEST(test, test1)
{
    std::vector<int> prices = {1, 2, 4};
    ASSERT_EQ(3, Solution().maxProfit(prices));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
