class BSTIterator:
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = list()
        self.pushLeft(root)
        
    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        node = self.stack.pop()
        self.pushLeft(node.right)
        return node.val
        
    def pushLeft(self, node):
        while node:
            self.stack.append(node)
            node = node.left
        
    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return True if self.stack else False