class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        if not root:
            return result

        path = [(0, root)]
        while path:
            pre, node = path.pop()
            if node:
                if not node.left and not node.right :
                    result += pre*10 + node.val
                
                path += [(pre*10 + node.val, node.right), (pre*10 + node.val, node.left)]
            
        return result

# class Solution:
#     def _sumNumbers(self, root, value):
#         if root:
#             self._sumNumbers(root.left, value*10+root.val)
#             self._sumNumbers(root.right, value*10+root.val)
#             if not root.left and not root.right:
#                 self.result += value*10 + root.val

#     def sumNumbers(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         self.result = 0
#         self._sumNumbers(root, 0)
#         return self.result