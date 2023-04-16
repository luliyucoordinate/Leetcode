#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0088-Merge-Sorted-Array/0088.cpp"

TEST(test, test1)
{
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    vector<int> expected = {1, 2};
    Solution().merge(nums1, 1, nums2, 1);
    ASSERT_EQ(expected, nums1);
}

TEST(test, test2)
{
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    vector<int> expected = {1, 2, 3, 4, 5, 6};
    Solution().merge(nums1, 3, nums2, 3);
    ASSERT_EQ(expected, nums1);
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
