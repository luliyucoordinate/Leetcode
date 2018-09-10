# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = ListNode(-1)
        h.next = head
        pre = h
        cur = head
        while cur != None:
            if pre and pre.val > cur.val:
                pre = h
            while pre.next != None and pre.next.val < cur.val:
                pre = pre.next
            pre.next, pre.next.next, cur = cur, pre.next, cur.next 
        return h.next
  

def createList():
    head = ListNode(0)
    cur = head
    for i in range(5, 1, -1):
        cur.next = ListNode(i)
        cur = cur.next
    return head
            
def printList(head):
    cur = head
    while cur != None:
        print(cur.val, '-->', end='')
        cur = cur.next

    print('NULL')

if __name__ == "__main__":
    head = createList()
    printList(head)
    res = Solution().insertionSortList(head)
    printList(res)