class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        cur = du = ListNode(0)
        du.next = head
        preSum = 0
        seen = {}
        
        while cur:
            preSum += cur.val
            node = seen.get(preSum, cur)
            if preSum in seen:
                cur = seen[preSum].next
                p = preSum + cur.val
                while p != preSum:
                    del seen[p]
                    cur = cur.next
                    p += cur.val
            seen[preSum] = node
            node.next = cur = cur.next
        return du.next