#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0021-Merge-Two-Sorted-Lists/0021.cpp"

#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *l1 = linkedListUtils.createSinglyLinkedList({1, 2, 3, 5});
    ListNode *l2 = linkedListUtils.createSinglyLinkedList({2, 4, 6});
    ASSERT_EQ(*linkedListUtils.createSinglyLinkedList({1, 2, 2, 3, 4, 5, 6}), *Solution().mergeTwoLists(l1, l2));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
