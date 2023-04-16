#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0092-Reverse-Linked-List-II/0092.cpp"
#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.createSinglyLinkedList({1, 2, 3, 4, 5});
    ListNode *expected = linkedListUtils.createSinglyLinkedList({1, 4, 3, 2, 5});

    ASSERT_EQ(*expected, *Solution().reverseBetween(head, 2, 4));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
