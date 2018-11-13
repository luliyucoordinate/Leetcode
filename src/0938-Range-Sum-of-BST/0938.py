# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        if not root or L > R:
            return 0
        
        if root.val < L:
            return self.rangeSumBST(root.right, L, R)

        if root.val > R:
            return self.rangeSumBST(root.left, L, R)

        return root.val + self.rangeSumBST(root.left, L, root.val - 1)+\
            self.rangeSumBST(root.right, root.val + 1, R)