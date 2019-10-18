class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = ""
        def postOrder(root):
            nonlocal res
            if not root:
                res += '# '
                return 
            postOrder(root.left)
            postOrder(root.right)
            res += str(root.val) + ' '
        postOrder(root)
        return res
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        datas = data.split()
        def deOrder():
            val = datas.pop()
            if val == '#':
                return 
            root = TreeNode(int(val))
            root.right = deOrder()
            root.left = deOrder()
            return root
        return deOrder()