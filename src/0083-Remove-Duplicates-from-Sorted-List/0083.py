# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head

        pre = None
        cur = head
        while cur != None:
            pre = cur
            cur = cur.next
            while cur != None and cur.val == pre.val:
                pre.next = cur.next
                cur = cur.next

        return head
           
        
def createList():
    head = ListNode(0)
    cur = head
    cur.next = ListNode(0)
    cur.next.next = ListNode(1)
    cur.next.next.next = ListNode(1)
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
    res = Solution().deleteDuplicates(head)
    printList(res)