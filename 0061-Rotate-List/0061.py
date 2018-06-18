# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head

        pre = head
        count = 1
        while pre.next != None:
            count += 1
            pre = pre.next

        pre.next = head
        n = count - k%count
        q = pre

        for _ in range(n):
            q = q.next

        ret = q.next
        q.next = None
        return ret


def createList():
    head = ListNode(0)
    cur = head
    for i in range(1, 3):
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
    res = Solution().rotateRight(head, 4)
    printList(res)