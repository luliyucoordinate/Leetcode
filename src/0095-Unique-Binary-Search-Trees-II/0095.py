# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return list()
        
        mem = dict()
        return self._generateTrees(1, n, mem)
        
    def _generateTrees(self, left, right, mem):
        if left > right:
            return [None]
        if (left, right) in mem:
            return mem[(left, right)]
        
        res = list()
        for i in range(left, right + 1):
            left_nodes = self._generateTrees(left, i - 1, mem)
            right_nodes = self._generateTrees(i + 1, right, mem)
            for left_node in left_nodes:
                for right_node in right_nodes:
                    root = TreeNode(i)
                    root.left = left_node
                    root.right = right_node
                    res.append(root)
                    
        mem[(left, right)] = res
        return res