#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0042-Trapping-Rain-Water/0042.cpp"

TEST(test, test1)
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    ASSERT_EQ(6, Solution().trap(height));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
