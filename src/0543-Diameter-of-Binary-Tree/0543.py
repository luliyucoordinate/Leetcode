class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res = 0

        def maxDiameter(root):
            nonlocal res
            if not root:
                return 0
            
            l = maxDiameter(root.left)
            r = maxDiameter(root.right)
            res = max(res, l + r)
            return max(l, r) + 1
        
        maxDiameter(root)
        return res