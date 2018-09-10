class Solution:
    def minimum(self, root):
        if not root.left:
            return root

        return self.minimum(root.left)

    def removeMin(self, root):
        if not root.left:
            return root.right
        
        root.left = self.removeMin(root.left)
        return root

    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return None
        
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
            return root
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
            return root
        else:
            if not root.left:
                return root.right

            if not root.right:
                return root.left

            tmp = self.minimum(root.right)
            tmp.right = self.removeMin(root.right)
            tmp.left = root.left
            return tmp
      