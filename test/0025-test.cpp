#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0025-Reverse-Nodes-in-k-Group/0025.cpp"

#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.createSinglyLinkedList({1, 2, 3, 4, 5});
    int k = 2;
    ListNode *expected = linkedListUtils.createSinglyLinkedList({2, 1, 4, 3, 5});
    ASSERT_EQ(*expected, *Solution().reverseKGroup(head, k));
}

TEST(test, test2)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.createSinglyLinkedList({1, 2, 3, 4, 5, 6, 7});
    ListNode *expected = linkedListUtils.createSinglyLinkedList({4, 3, 2, 1, 5, 6, 7});
    ASSERT_EQ(*expected, *Solution().reverseKGroup(head, 4));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
