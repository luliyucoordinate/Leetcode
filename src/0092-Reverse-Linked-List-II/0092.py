# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if head == None or head.next == None or m >= n or m < 0 or n < 0:
            return head

        h = ListNode(-1)
        h.next = head
        pre = h
        cur = head
        i = 1
        while i < m and cur != None:
            pre = cur
            cur = cur.next
            i += 1

        t1 = pre
        t2 = cur

        while i <= n and cur != None:
            lat = cur.next
            cur.next = pre
            pre = cur 
            cur = lat
            i += 1

        t1.next = pre
        t2.next = cur
        return h.next
    
        
def createList():
    head = ListNode(0)
    cur = head
    for i in range(1, 10):
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
    m = 2
    n = 6
    res = Solution().reverseBetween(head, m, n)
    printList(res)