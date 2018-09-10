# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def _merge(self, head1, head2):
        if head1 == None or head2 == None:
            return head2 or head1

        h = ListNode(-1)
        tmp = h
        while head1 != None and head2 != None:
            if head1.val < head2.val:
                tmp.next = head1
                head1 = head1.next
            else:
                tmp.next = head2
                head2 = head2.next
            tmp = tmp.next
        
        tmp.next = head1 or head2

        return h.next
        

    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        
        lat = pre = head
        while lat.next != None and lat.next.next != None:
            lat = lat.next.next
            pre = pre.next

        lat = pre.next
        pre.next = None
        return self._merge(self.sortList(head), self.sortList(lat))


def createList():
    head = ListNode(0)
    cur = head
    for i in range(1, 6):
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
    res = Solution().sortList(head)
    printList(res)