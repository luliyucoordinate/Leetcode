#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0041-First-Missing-Positive/0041.cpp"

TEST(test, test1)
{
    std::vector<int> nums = {1, 2, 0};
    ASSERT_EQ(3, Solution().firstMissingPositive(nums));
}

TEST(test, test2)
{
    std::vector<int> nums = {};
    ASSERT_EQ(1, Solution().firstMissingPositive(nums));
}

TEST(test, test3)
{
    std::vector<int> nums = {3, 4, -1, 1};
    ASSERT_EQ(2, Solution().firstMissingPositive(nums));
}

TEST(test, test4)
{
    std::vector<int> nums = {2};
    ASSERT_EQ(1, Solution().firstMissingPositive(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
