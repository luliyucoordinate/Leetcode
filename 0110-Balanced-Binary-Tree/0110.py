# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:        
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        def height(node, h):
            if not node:
                return h

            return max(height(node.left, h + 1), height(node.right, h + 1))

        if abs(height(root.left, 0) - height(root.right, 0)) > 1:
            return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)
        
        

if __name__ == "__main__":
    root = [3,9,20,None,None,15,7]
    print(Solution().isBalanced(root))

        