class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        res = 0.0
        def dfs(root):
            nonlocal res
            if not root:
                return 0, 0
            
            l, r = dfs(root.left), dfs(root.right)
            values, nodes = l[0] + r[0] + root.val, l[1] + r[1] + 1
            res = max(res, values/nodes)
            return values, nodes
        
        dfs(root)
        return res