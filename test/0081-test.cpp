#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0081-Search-in-Rotated-Sorted-Array-II/0081.cpp"

TEST(test, test1)
{
    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    ASSERT_EQ(true, Solution().search(nums, 0));
}

TEST(test, test2)
{
    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    ASSERT_EQ(false, Solution().search(nums, 30));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
