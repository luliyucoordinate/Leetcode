#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0079-Word-Search/0079.cpp"

TEST(test, test1)
{
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    ASSERT_EQ(true, Solution().exist(board, "ABCEFSADEESE"));
}

TEST(test, test2)
{
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    
    ASSERT_EQ(true, Solution().exist(board, "SEE"));

    ASSERT_EQ(false, Solution().exist(board, "ABCD"));
}

TEST(test, test3)
{
    std::vector<std::vector<char>> board = {
        {'a'},
        {'a'},
    };

    ASSERT_EQ(false, Solution().exist(board, "aaa"));
}

TEST(test, test4)
{
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'H', 'I'},
        {'K', 'E', 'H', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    ASSERT_EQ(true, Solution().exist(board, "ABHISHEK"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
