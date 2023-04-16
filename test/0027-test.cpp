#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0027-Remove-Element/0027.cpp"

TEST(test, test1)
{
    vector<int> nums = {3, 2, 2, 3};
    ASSERT_EQ(2, Solution().removeElement(nums, 3));
}

TEST(test, test2)
{
    vector<int> nums = {2, 2, 3};
    ASSERT_EQ(1, Solution().removeElement(nums, 2));
}

TEST(test, test3)
{
    vector<int> nums = {1};
    ASSERT_EQ(0, Solution().removeElement(nums, 1));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
