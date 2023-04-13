#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0024-Swap-Nodes-in-Pairs/0024.cpp"

#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.createSinglyLinkedList({1, 2, 3, 4});
    ListNode *expected = linkedListUtils.createSinglyLinkedList({2, 1, 4, 3});
    ASSERT_EQ(*expected, *Solution().swapPairs(head));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
