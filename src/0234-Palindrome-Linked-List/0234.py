# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None:
            return True

        lat = head.next
        pre = head
        while lat != None and lat.next != None:
            lat = lat.next.next
            pre = pre.next

        cur = pre.next
        pre.next = None
        p = None
        while cur != None:
            q = cur.next
            cur.next = p
            p = cur
            cur = q

        while p != None and head != None:
            if p.val != head.val:
                return False
            p = p.next
            head = head.next

        return True


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
    res = Solution().isPalindrome(head)
    print(res)