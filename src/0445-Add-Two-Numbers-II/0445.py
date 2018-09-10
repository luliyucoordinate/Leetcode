# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        stack_list1, stack_list2, stack_list3 = list(), list(), list()
        h = ListNode(-1)
        cur = h

        while l1 != None:
            stack_list1.append(l1.val)
            l1 = l1.next

        while l2 != None:
            stack_list2.append(l2.val)
            l2 = l2.next

        add = 0
        while stack_list1 or stack_list2 or add:
            if stack_list1:
                top1 = stack_list1.pop()
            else:
                top1 = 0
            if stack_list2:
                top2 = stack_list2.pop()
            else:
                top2 = 0
            val = top1 + top2 + add
            add = val // 10
            stack_list3.append(val%10)

        while stack_list3:
            cur.next = ListNode(stack_list3.pop())
            cur = cur.next

        return h.next      

def createList1():
    head = ListNode(7)
    cur = head
    cur.next = ListNode(2)
    cur.next.next = ListNode(4)
    cur.next.next.next = ListNode(3)
    return head

def createList2():
    head = ListNode(5)
    cur = head
    cur.next = ListNode(6)
    cur.next.next = ListNode(4)
    return head
            
def printList(head):
    cur = head
    while cur != None:
        print(cur.val, '-->', end='')
        cur = cur.next

    print('NULL')

if __name__ == "__main__":
    l1 = createList1()
    printList(l1)
    l2 = createList2()
    printList(l2)
    res = Solution().addTwoNumbers(l1, l2)
    printList(res)