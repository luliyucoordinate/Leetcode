# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        result = ListNode(-1)
        cur = result
        for i in lists:
            while i:
                val = i.val
                cur.next = ListNode(val)
                cur = cur.next
                i = i.next
        
        return result.next

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
    l1 = createList()
    l2 = createList()
    l3 = createList()
    printList(l1)
    l = list(l1)
    l.append(l2)
    l.append(l3)
    res = Solution().mergeKLists(l)
    printList(res)