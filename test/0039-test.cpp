#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0039-Combination-Sum/0039.cpp"

TEST(test, test1)
{
    std::vector<int> candidates = {2, 3, 6, 7};
    std::vector<std::vector<int>> expected = {};
    expected.push_back({2, 2, 3});
    expected.push_back({7});

    ASSERT_EQ(expected, Solution().combinationSum(candidates, 7));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
