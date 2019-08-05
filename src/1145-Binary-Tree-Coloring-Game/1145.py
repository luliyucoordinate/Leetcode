class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        c = [0, 0]
        def helper(node):
            if not node: 
                return 0
            l, r = helper(node.left), helper(node.right)
            if node.val == x:
                c[0], c[1] = l, r
            return l + r + 1
        return helper(root) // 2 < max(max(c), n - sum(c) - 1)