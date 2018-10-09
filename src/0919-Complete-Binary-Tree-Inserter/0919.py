# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class CBTInserter:
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.data = list()
        self.data.append(root)
        for node in self.data:
            if node.left:
                self.data.append(node.left)
            if node.right:
                self.data.append(node.right)
        
    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        parent = self.data[(len(self.data) - 1)//2]
        if parent.left:
            parent.right = TreeNode(v)
            self.data += [parent.right]
        else:
            parent.left = TreeNode(v)
            self.data += [parent.left]

        return parent.val
        
    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.data[0]
        