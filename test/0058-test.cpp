#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0058-Length-of-Last-Word/0058.cpp"

TEST(test, test1)
{
    ASSERT_EQ(5, Solution().lengthOfLastWord("Hello World"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
