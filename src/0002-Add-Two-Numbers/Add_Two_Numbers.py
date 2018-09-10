# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = ListNode(0)
        cur = ret
        add = 0
        
        while l1 or l2 or add:
            val = (l1.val if l1 else 0) + (l2.val if l2 else 0) + add
            add = val // 10
            cur.next = ListNode(val % 10)
            cur = cur.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return ret.next


if __name__ == '__main__':
    l1 = ListNode(0)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)
    l2 = ListNode(0)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)
    ret = Solution().addTwoNumbers(l1, l2)
    while ret != None:
        print(ret.val)
        ret = ret.next