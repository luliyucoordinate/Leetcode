#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0123-Best-Time-to-Buy-and-Sell-Stock-III/0123.cpp"

TEST(test, test1)
{
    std::vector<int> prices = {1};
    ASSERT_EQ(0, Solution().maxProfit(prices));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
