#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0033-Search-in-Rotated-Sorted-Array/0033.cpp"

TEST(test, test1)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int expected = 3;
    int target = 7;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test2)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int expected = 4;
    int target = 0;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test3)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int expected = 1;
    int target = 5;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test4)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int expected = -1;
    int target = 3;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test5)
{
    vector<int> nums = {1};
    int expected = -1;
    int target = 0;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test6)
{
    vector<int> nums = {1, 3, 5};
    int expected = -1;
    int target = 4;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test7)
{
    vector<int> nums = {1, 3, 5};
    int expected = -1;
    int target = 6;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test8)
{
    vector<int> nums = {1, 3, 5};
    int expected = -1;
    int target = 2;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test9)
{
    vector<int> nums = {5, 1, 3};
    int expected = -1;
    int target = 4;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test10)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int expected = 3;
    int target = 4;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test11)
{
    vector<int> nums = {5, 1, 2, 3, 4};
    int expected = 1;
    int target = 1;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test12)
{
    vector<int> nums = {8, 9, 2, 3, 4};
    int expected = 1;
    int target = 9;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

TEST(test, test13)
{
    vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
    int expected = 4;
    int target = 8;
    ASSERT_EQ(expected, Solution().search(nums, target));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
