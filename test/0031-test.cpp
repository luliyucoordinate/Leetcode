#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0031-Next-Permutation/0031.cpp"

TEST(test, test1)
{
    vector<int> nums = {1, 2, 3};
    Solution().nextPermutation(nums);
    ASSERT_EQ(vector<int>({1, 3, 2}), nums);
}

TEST(test, test2)
{
    vector<int> nums = {1, 2, 4, 6, 3};
    Solution().nextPermutation(nums);
    ASSERT_EQ(vector<int>({1, 2, 6, 3, 4}), nums);
}

TEST(test, test3)
{
    vector<int> nums = {1, 2, 4, 6, 3, 2, 1};
    Solution().nextPermutation(nums);
    ASSERT_EQ(vector<int>({1, 2, 6, 1, 2, 3, 4}), nums);
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
