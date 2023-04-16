#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0072-Edit-Distance/0072.cpp"

TEST(test, test1)
{
    ASSERT_EQ(1, Solution().minDistance("Ada", "Adam"));
}

TEST(test, test2)
{
    ASSERT_EQ(5, Solution().minDistance("Ashmi", "Chheda"));
}


GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
