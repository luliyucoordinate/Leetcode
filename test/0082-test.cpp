#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0082-Remove-Duplicates-from-Sorted-List-II/0082.cpp"
#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.contructLinkedList({1, 2, 3, 3, 4, 4, 5});
    ListNode *expected = linkedListUtils.contructLinkedList({1, 2, 5});

    ASSERT_EQ(*expected, *Solution().deleteDuplicates(head));
}

TEST(test, test2)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.contructLinkedList({1, 1, 1, 2, 3});
    ListNode *expected = linkedListUtils.contructLinkedList({2, 3});

    ASSERT_EQ(*expected, *Solution().deleteDuplicates(head));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
