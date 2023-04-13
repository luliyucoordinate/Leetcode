#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0034-Find-First-and-Last-Position-of-Element-in-Sorted-Array/0034.cpp"

TEST(test, test1)
{
    vector<int> nums = {1, 2, 3};
    ASSERT_EQ(vector<int>({1, 1}), Solution().searchRange(nums, 2));
}

TEST(test, test2)
{
    vector<int> nums = {};
    ASSERT_EQ(vector<int>({-1, -1}), Solution().searchRange(nums, 0));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
