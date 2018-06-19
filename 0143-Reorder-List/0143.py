# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return

        pre = head
        lat = head.next
        while lat != None and lat.next != None:
            pre = pre.next
            lat = lat.next.next

        p = pre.next
        pre.next = None
        # reverse
        
        cur = None        
        while p != None:
            q = p.next
            p.next = cur
            cur = p 
            p = q
               
        pre = head
        while pre != None and cur != None:
            tmp = cur.next  
            cur.next = pre.next
            pre.next = cur
            pre = pre.next.next
            cur = tmp 
                   
       

def createList():
    head = ListNode(1)
    cur = head
    for i in range(2, 5):
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
    Solution().reorderList(head)
    printList(head)