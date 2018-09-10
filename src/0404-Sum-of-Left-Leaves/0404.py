class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        if not root:
            return 0
            
        if root.left and root.left.left == None and root.left.right == None:
            result += root.left.val

        result += self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
        return result