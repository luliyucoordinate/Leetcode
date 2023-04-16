#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0012-Integer-to-Roman/0012.cpp"

TEST(test, test1)
{
  ASSERT_EQ("XII", Solution().intToRoman(12));
}

TEST(test, test2)
{
  ASSERT_EQ("M", Solution().intToRoman(1000));
}

TEST(test, test3)
{
  ASSERT_EQ("MMMCMXCIX", Solution().intToRoman(3999));
}

GTEST_API_ int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
