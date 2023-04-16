#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0006-ZigZag-Conversion/0006.cpp"

TEST(test, test1)
{
    ASSERT_EQ("PAHNAPLSIIGYIR", Solution().convert("PAYPALISHIRING", 3));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
