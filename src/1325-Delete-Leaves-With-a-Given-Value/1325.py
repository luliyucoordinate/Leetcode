class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if not root:
            return None
        
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        return None if root.val == target and root.left == root.right else root