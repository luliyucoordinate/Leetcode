#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0096-Unique-Binary-Search-Trees/0096.cpp"

TEST(test, test1)
{
    ASSERT_EQ(5, Solution().numTrees(3));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
