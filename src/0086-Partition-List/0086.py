# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# class Solution:
#     def partition(self, head, x):
#         """
#         :type head: ListNode
#         :type x: int
#         :rtype: ListNode
#         """
#         if head == None or head.next == None:
#             return head

#         pre_min, pre_max, cur_min, cur_max = None, None, None, None
#         cur = head

#         while cur != None:
#             if cur.val < x and pre_min == None:
#                 pre_min = cur_min = cur
#             elif cur.val >= x and pre_max == None:
#                 pre_max = cur_max = cur
#             elif cur.val < x and pre_min != None:
#                 cur_min.next = cur
#                 cur_min = cur_min.next
#             elif cur.val >= x and pre_max != None:
#                 cur_max.next = cur
#                 cur_max = cur_max.next

#             cur = cur.next

#         if cur_min != None:
#             cur_min.next = pre_max

#         if cur_max != None:
#             cur_max.next = None

#         if pre_min != None:
#             return pre_min
#         return pre_max

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head

        cur = head
        pre_min = cur_min = ListNode(-1)
        pre_max = cur_max = ListNode(-1)

        while cur != None:
            if cur.val < x:
                cur_min.next = cur
                cur_min = cur_min.next
            else:
                cur_max.next = cur
                cur_max = cur_max.next

            cur = cur.next

        cur_min.next = pre_max.next
        cur_max.next = None
        return pre_min.next

def createList():
    head = ListNode(0)
    cur = head
    cur.next = ListNode(1)
    cur.next.next = ListNode(3)
    cur.next.next.next = ListNode(0)
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
    x = 1
    res = Solution().partition(head, x)
    printList(res)