class Solution:
    def flipEquiv(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        if root1 == None or root2 == None:
            return root1 == root2
        
        if root1.val != root2.val:
            return False
        
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or\
               (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))