#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "../src/0086-Partition-List/0086.cpp"
#include "../util/ListNode.h"
#include "LinkedListUtils.cpp"

TEST(test, test1)
{
    LinkedListUtils linkedListUtils;
    ListNode *head = linkedListUtils.contructLinkedList({1, 4, 3, 2, 5, 2});
    ListNode *expected = linkedListUtils.contructLinkedList({1, 2, 2, 4, 3, 5});

    ASSERT_EQ(*expected, *Solution().partition(head, 3));
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
