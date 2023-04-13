#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0011-Container-With-Most-Water/0011.cpp"

TEST(test, test1)
{
  std::vector<int> height = {1, 1};
  int expected = 1;
  ASSERT_EQ(expected, Solution().maxArea(height));
}

GTEST_API_ int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
