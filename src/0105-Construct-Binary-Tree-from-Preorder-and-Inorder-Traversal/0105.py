# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not preorder:
            return 
        
        root = TreeNode(preorder[0])
        stack = [root]
        i = 0
        
        for node in preorder[1:]:
            parent = stack[-1]
            
            if parent.val != inorder[i]:
                parent.left = TreeNode(node)
                stack.append(parent.left)
                
            else:
                while stack and stack[-1].val == inorder[i]:
                    parent = stack.pop()
                    i += 1
                parent.right = TreeNode(node)
                stack.append(parent.right)
                
        return root
        
if __name__ == "__main__":
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    Solution().buildTree(preorder, inorder)