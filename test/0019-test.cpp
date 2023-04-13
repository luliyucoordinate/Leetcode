#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0019-Remove-Nth-Node-From-End-of-List/0019.cpp"

#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.contructLinkedList({1, 2, 3, 4, 5});
    ListNode *expected = linkedListUtils.contructLinkedList({1, 2, 3, 5});
    ASSERT_EQ(*expected, *Solution().removeNthFromEnd(head, 2));
}

TEST(test, test2)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.contructLinkedList({11});
    ListNode *expected = linkedListUtils.contructLinkedList({});
    ASSERT_EQ(*expected, *Solution().removeNthFromEnd(head, 1));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
