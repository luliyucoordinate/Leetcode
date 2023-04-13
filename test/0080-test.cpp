#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0080-Remove-Duplicates-from-Sorted-Array-II/0080.cpp"

TEST(test, test1)
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    ASSERT_EQ(5, Solution().removeDuplicates(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
