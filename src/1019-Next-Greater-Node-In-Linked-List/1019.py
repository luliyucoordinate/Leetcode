class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        res, stack = list(), list()
        while head:
            while stack and stack[-1][1] < head.val:
                res[stack.pop()[0]] = head.val
            stack.append([len(res), head.val])
            res.append(0)
            head = head.next
        return res