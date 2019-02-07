# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def smallestFromLeaf(self, root: 'TreeNode',path="") -> 'str':
        if not root:
            return "~"
        s = chr(root.val + 97)
        return s if root.left == root.right else min(self.smallestFromLeaf(root.left)\
                                                     + s, self.smallestFromLeaf(root.right) + s)