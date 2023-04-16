#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0055-Jump-Game/0055.cpp"

TEST(test, test1)
{
    vector<int> nums = {0, 2, 3};
    ASSERT_EQ(false, Solution().canJump(nums));
}

TEST(test, test2)
{
    vector<int> nums = {1, 2};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test3)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test4)
{
    vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test5)
{
    vector<int> nums = {2, 0, 0};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test6)
{
    vector<int> nums = {2, 0};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test7)
{
    vector<int> nums = {1, 1, 0, 1};
    ASSERT_EQ(false, Solution().canJump(nums));
}

TEST(test, test8)
{
    vector<int> nums = {0};
    ASSERT_EQ(true, Solution().canJump(nums));
}

TEST(test, test9)
{
    vector<int> nums = {3, 2, 1, 0, 4};
    ASSERT_EQ(false, Solution().canJump(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
