class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        def dfs(node, p, gp):
            if node:
                return dfs(node.left, node.val, p) + \
                dfs(node.right, node.val, p) + \
                (0 if gp % 2 != 0 else node.val)
            return 0
        
        return dfs(root, 1, 1)