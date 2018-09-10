# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        import heapq 
        result = ListNode(-1)
        cur = result
        p = list()
        x = 0
        for i in lists:
            while i:
                heapq.heappush(p, (i.val, x, i))
                i = i.next
                x += 1

        while p:
            cur.next = heapq.heappop(p)[1]
            cur = cur.next

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