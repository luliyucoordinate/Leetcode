class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        total, mod, res = 0, 10**9 + 7, 0
        def dfs(node):
            nonlocal res
            if not node:
                return 0
            
            l, r = dfs(node.left), dfs(node.right)
            res =  max(res, l * (total - l), r * (total - r))
            return l + r + node.val
        
        total = dfs(root)
        dfs(root)
        return res % mod