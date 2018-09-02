# class Solution:
#     def _isValidBST(self, root, left=None, right=None):
#         if not root:
#             return True

#         if left and left.val >= root.val:
#             return False

#         if right and right.val <= root.val:
#             return False

#         return self._isValidBST(root.left, left, root) and self._isValidBST(root.right, root, right)

#     def isValidBST(self, root):
#         """
#         :type root: TreeNode
#         :rtype: bool
#         """
#         return self._isValidBST(root)


class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        pre = None
        stack = list()
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                if pre and root.val <= pre.val:
                        return False
                
                pre = root
                root = root.right

        return True