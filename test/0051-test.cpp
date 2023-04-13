#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0051-N-Queens/0051.cpp"

TEST(test, test1)
{
    int n = 4;
    std::vector<std::vector<std::string>> expected = {};
    expected.push_back({".Q..", "...Q", "Q...", "..Q."});
    expected.push_back({"..Q.", "Q...", "...Q", ".Q.."});
    vector<vector<string>> actual = Solution().solveNQueens(n);
    ASSERT_EQ(expected, actual);
}


GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
