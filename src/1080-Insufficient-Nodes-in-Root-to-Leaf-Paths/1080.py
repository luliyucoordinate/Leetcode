class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        if not root:
            return None
        
        if root.left == root.right:
            return None if root.val < limit else root
        
        root.left = self.sufficientSubset(root.left, limit - root.val)
        root.right = self.sufficientSubset(root.right, limit - root.val)
        return None if root.left == root.right else root