class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res = float('-inf')
        def maxPath(node):
            nonlocal res 
            if not node:
                return 0
            
            left = max(0, maxPath(node.left))
            right = max(0, maxPath(node.right))
            res = max(res, left + right + node.val)
            return max(left, right) + node.val
        
        maxPath(root)
        return res