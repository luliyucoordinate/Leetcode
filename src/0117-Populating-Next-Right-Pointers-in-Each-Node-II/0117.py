# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        while root:
            node = dummy = TreeLinkNode(0)
            while root:
                if root.left: 
                    node.next = node = root.left
                    
                if root.right: 
                    node.next = node = root.right
                    
                root = root.next
            root = dummy.next