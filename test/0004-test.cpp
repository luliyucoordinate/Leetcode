#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0004-Median-of-Two-Sorted-Arrays/0004.cpp"

TEST(test, test1)
{
    std::vector<int> A = {1, 3};
    std::vector<int> B = {2};
    ASSERT_EQ(2.0, Solution().findMedianSortedArrays(A, B));
}


TEST(test, test2)
{
    std::vector<int> A = {1, 2};
    std::vector<int> B = {3, 4};
    ASSERT_EQ(2.5, Solution().findMedianSortedArrays(A, B));
}


GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
