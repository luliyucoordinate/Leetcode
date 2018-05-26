# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        assert (n >= 0)
        dumNode = ListNode(0)
        dumNode.next = head
        p = dumNode
        q = dumNode
        for _ in range(n + 1):
            assert (q)
            q = q.next

        while q != None:
            p = p.next
            q = q.next

        delNode = p.next
        p.next = delNode.next
        delNode = None
        retNode = dumNode.next
        dumNode = None
        return retNode

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
    res = Solution().removeNthFromEnd(head, 2)
    printList(res)