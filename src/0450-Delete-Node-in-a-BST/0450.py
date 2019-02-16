class Solution:
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
            
            minNode = root.right
            while minNode.left:
                minNode = minNode.left
            root.val = minNode.val
            root.right = self.deleteNode(root.right, minNode.val)     
            return root