class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        res = 0
        def dfs(root):
            nonlocal res
            if not root: return [-1, -1]
            left, right = dfs(root.left), dfs(root.right)
            res = max(res, left[1] + 1, right[0] + 1)
            return left[1] + 1, right[0] + 1
        
        dfs(root)
        return res   