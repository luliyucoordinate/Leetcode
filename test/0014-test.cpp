#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0014-Longest-Common-Prefix/0014.cpp"

TEST(test, test1)
{
  std::vector<std::string> strs = {"a", "b"};
  ASSERT_EQ("", Solution().longestCommonPrefix(strs));
}

TEST(test, test2)
{
  std::vector<std::string> strs = {"leetcode", "lead"};
  ASSERT_EQ("le", Solution().longestCommonPrefix(strs));
}

TEST(test, test3)
{
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  ASSERT_EQ("fl", Solution().longestCommonPrefix(strs));
}

TEST(test, test4)
{
  std::vector<std::string> strs = {};
  ASSERT_EQ("", Solution().longestCommonPrefix(strs));
}

TEST(test, test5)
{
  std::vector<std::string> strs = {"a"};
  ASSERT_EQ("a", Solution().longestCommonPrefix(strs));
}

TEST(test, test6)
{
  std::vector<std::string> strs = {"c", "c"};
  ASSERT_EQ("c", Solution().longestCommonPrefix(strs));
}

GTEST_API_ int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
