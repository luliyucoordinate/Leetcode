# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def height(t):
            h = -1
            while t:
                h += 1
                t = t.left
            return h
        
        h = height(root)

        nodes = 0
        while root:
            if height(root.right) == h - 1: #满二叉树
                nodes += 2**h
                root = root.right
            else:
                nodes += 2**(h - 1)
                root = root.left

            h -= 1

        return nodes