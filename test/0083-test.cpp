#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0083-Remove-Duplicates-from-Sorted-List/0083.cpp"
#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.createSinglyLinkedList({1, 1, 2, 3, 3});
    ListNode *expected = linkedListUtils.createSinglyLinkedList({1, 2, 3});

    ASSERT_EQ(*expected, *Solution().deleteDuplicates(head));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
