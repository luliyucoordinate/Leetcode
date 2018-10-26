# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not postorder:
            return 
        
        postorder.reverse()
        root = TreeNode(postorder[0])
        stack = [root]
        i = len(inorder) - 1

        for node in postorder[1:]:
            parent = stack[-1]
            
            if parent.val != inorder[i]:
                parent.right = TreeNode(node)
                stack.append(parent.right)     
            else:
                while stack and stack[-1].val == inorder[i]:
                    parent = stack.pop()
                    i -= 1
                parent.left = TreeNode(node)
                stack.append(parent.left)
                
        return root

if __name__ == "__main__":
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    Solution().buildTree(inorder, postorder)