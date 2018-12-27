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
        if not root:
            return 
        
        if root.left:
            root.left.next = root.right
            
        if root.right and root.next:
            root.right.next = root.next.left
            
        self.connect(root.left)
        self.connect(root.right)
                