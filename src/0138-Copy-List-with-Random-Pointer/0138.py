# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        
        h1, h2, h = head, head, head
        while h1:
            node = RandomListNode(h1.label)
            node.next = h1.next 
            h1.next = node
            h1 = node.next
            
        while h2:
            if h2.random:
                h2.next.random = h2.random.next
            h2 = h2.next.next
            
        res = h.next
        while h:
            tmp = h.next
            h.next = tmp.next
            if h.next:
                tmp.next = h.next.next
            h = h.next
            
        return res