# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dumHead = ListNode(0)
        dumHead.next = head
        pre = dumHead
        while pre.next != None and pre.next.next != None:
            node1 = pre.next
            node2 = node1.next
            lat = node2.next

            node2.next = node1
            node1.next = lat
            pre.next = node2

            pre = node1

        retNode = dumHead.next
        dumHead = None
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
    res = Solution().swapPairs(head)
    printList(res)