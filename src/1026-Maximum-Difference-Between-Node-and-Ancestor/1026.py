class Solution:
    def maxAncestorDiff(self, root: TreeNode, mn=float('inf'), mx=0) -> int:
        return max(self.maxAncestorDiff(root.left, min(mn, root.val), max(mx, root.val)), \
            self.maxAncestorDiff(root.right, min(mn, root.val), max(mx, root.val))) \
            if root else mx - mn 