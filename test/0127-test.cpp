#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0127-Word-Ladder/0127.cpp"

TEST(test, test1)
{
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};
    ASSERT_EQ(0, Solution().ladderLength("hit", "cog", wordList));
}

TEST(test, test2)
{
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    ASSERT_EQ(5, Solution().ladderLength("hit", "cog", wordList));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
