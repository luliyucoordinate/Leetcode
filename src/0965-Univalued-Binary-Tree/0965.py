class Solution:    
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        if (root.left and root.val != root.left.val) or (root.right and root.val != root.right.val):
            return False
        
        return self.isUnivalTree(root.left) and self.isUnivalTree(root.right)