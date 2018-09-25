# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        check = self._rob(root)
        return max(check[0], check[1])

    def _rob(self, root):
        if not root:
            return [0, 0]

        l, r = self._rob(root.left), self._rob(root.right)
        return l[1] + r[1] + root.val, max(l) + max(r)