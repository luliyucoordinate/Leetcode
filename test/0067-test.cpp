#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0067-Add-Binary/0067.cpp"

TEST(test, test1)
{
    ASSERT_EQ("100", Solution().addBinary("11", "1"));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
