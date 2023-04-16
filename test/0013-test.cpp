#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0013-Roman-to-Integer/0013.cpp"

TEST(test, test1)
{
  ASSERT_EQ(12, Solution().romanToInt("XII"));
}

TEST(test, test2)
{
  ASSERT_EQ(1000, Solution().romanToInt("M"));
}

TEST(test, test3)
{
  ASSERT_EQ(3999, Solution().romanToInt("MMMCMXCIX"));
}

GTEST_API_ int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
