#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0016-3Sum-Closest/0016.cpp"

TEST(test, test1)
{
    vector<int> nums = {-1, 2, 1, -4};
    ASSERT_EQ(2, Solution().threeSumClosest(nums, 1));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
