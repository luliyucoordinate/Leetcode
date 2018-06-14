# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def _reverseGroup(self, pre, lat):
        lpre = pre.next
        cur = lpre.next
        while cur != lat:
            lpre.next = cur.next
            cur.next = pre.next
            pre.next = cur
            cur = lpre.next

        return lpre

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
        
        t = 1
        while cur != None:
            if t % k == 0:
                pre = self._reverseGroup(pre, cur.next)
                cur = pre.next
            else:
                cur = cur.next
            t += 1
           
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
    res = Solution().reverseKGroup(head, 3)
    printList(res)