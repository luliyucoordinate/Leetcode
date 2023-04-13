#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0053-Maximum-Subarray/0053.cpp"

TEST(test, test1)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ASSERT_EQ(6, Solution().maxSubArray(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
