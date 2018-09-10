class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        result = list()
        if root == None:
            return result

        if root.left == None and root.right == None:
            result.append(str(root.val))
            return result

        left = self.binaryTreePaths(root.left)
        for i in range(len(left)):
            result.append(str(root.val) + '->' + left[i])

        right = self.binaryTreePaths(root.right)
        for i in range(len(right)):
            result.append(str(root.val) + '->' + right[i])

        return result