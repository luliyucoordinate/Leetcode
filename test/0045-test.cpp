#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0045-Jump-Game-II/0045.cpp"

TEST(test, test1)
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    ASSERT_EQ(2, Solution().jump(nums));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
