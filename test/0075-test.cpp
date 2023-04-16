#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0075-Sort-Colors/0075.cpp"

TEST(test, test1)
{
    std::vector<int> nums = {2, 2, 1};
    Solution().sortColors(nums);
    ASSERT_EQ(std::vector<int>({1, 2, 2}), nums);
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
