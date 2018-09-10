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
        h = ListNode(-1)
        h.next = head
        pre = h
        cur = head
        while cur != None: 
            duplicate = False          
            while cur.next != None and cur.val == cur.next.val:
                cur = cur.next
                duplicate = True
            
            if duplicate == False:
                pre = cur
            else:
                pre.next = cur.next

            cur = cur.next

        return h.next
           
        
def createList():
    head = ListNode(0)
    cur = head
    cur.next = ListNode(0)
    cur.next.next = ListNode(1)
    cur.next.next.next = ListNode(2)
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