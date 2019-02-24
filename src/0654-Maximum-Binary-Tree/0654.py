class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        stack = list()
        for n in nums:
            cur = TreeNode(n)
            while stack and stack[-1].val < n:
                cur.left = stack.pop()
                
            if stack:
                stack[-1].right = cur
            stack.append(cur)
            
        return stack[0]