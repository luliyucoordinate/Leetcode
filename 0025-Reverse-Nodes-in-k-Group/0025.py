# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        h = ListNode(-1)
        h.next = head
        pre = h
        cur = head
        n = 0
        while cur != None:
            n += 1
            cur = cur.next
        
        while n >= k:
            cur = pre.next
            for _ in range(k - 1):
                lat = cur.next
                cur.next = lat.next
                lat.next = pre.next
                pre.next = lat
            
            pre = cur
            n -= k
        
        return h.next


def createList():
    head = ListNode(0)
    cur = head
    for i in range(1, 2):
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
    res = Solution().reverseKGroup(head, 2)
    printList(res)