#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0002-Add-Two-Numbers/Add_Two_Numbers.cpp"
#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"


TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *l1 = linkedListUtils.contructLinkedList({2, 4, 3});
    ListNode *l2 = linkedListUtils.contructLinkedList({5, 6, 4});
    ListNode *expected = linkedListUtils.contructLinkedList({7, 0, 8});
    ASSERT_EQ(*expected, *Solution().addTwoNumbers(l1, l2));
}


TEST(test, test2)
{
    LinkedListUtils linkedListUtils;
    ListNode *l1 = linkedListUtils.contructLinkedList({1, 8});
    ListNode *l2 = linkedListUtils.contructLinkedList({0});
    ListNode *expected = linkedListUtils.contructLinkedList({1, 8});
    ASSERT_EQ(*expected, *Solution().addTwoNumbers(l1, l2));
}


TEST(test, test3)
{
    LinkedListUtils linkedListUtils;
    ListNode *l1 = linkedListUtils.contructLinkedList({5});
    ListNode *l2 = linkedListUtils.contructLinkedList({5});
    ListNode *expected = linkedListUtils.contructLinkedList({0, 1});
    ASSERT_EQ(*expected, *Solution().addTwoNumbers(l1, l2));
}



GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
