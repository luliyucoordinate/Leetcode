#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0084-Largest-Rectangle-in-Histogram/0084.cpp"


TEST(test, test1)
{
    std::vector<int> nums = {2, 1, 5, 6, 2, 3};
    ASSERT_EQ(10, Solution().largestRectangleArea(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
