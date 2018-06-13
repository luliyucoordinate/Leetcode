# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        h = ListNode(-1)
        cur = h

        cur1 = l1
        cur2 = l2

        while cur1 != None and cur2 != None:
            if cur1.val <= cur2.val:
                cur.next = cur1
                cur1 = cur1.next
            else:
                cur.next = cur2
                cur2 = cur2.next
            cur = cur.next
        
        if cur1 != None:
            cur.next = cur1

        if cur2 != None:
            cur.next = cur2
        return h.next
           
        
def createList():
    head = ListNode(0)
    cur = head
    cur.next = ListNode(0)
    cur.next.next = ListNode(1)
    cur.next.next.next = ListNode(2)
    return head
            
def printList(head):
    cur = head
    while cur != None:
        print(cur.val, '-->', end='')
        cur = cur.next

    print('NULL')

if __name__ == "__main__":
    l1 = createList()
    printList(l1)
    l2 = createList()
    printList(l2)
    res = Solution().mergeTwoLists(l1, l2)
    printList(res)