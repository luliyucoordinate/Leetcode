class Solution:
    pre = 0
    def bstToGst(self, root: TreeNode) -> TreeNode:
        if root.right: 
            self.bstToGst(root.right)
            
        root.val = self.pre = self.pre + root.val
        if root.left: 
            self.bstToGst(root.left)
        return root