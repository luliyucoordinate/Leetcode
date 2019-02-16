class Solution:
    def getMinimumDifference(self, root: 'TreeNode') -> 'int':
        res, pre = float('inf'), float('-inf')
        
        def inOrder(root):
            nonlocal res, pre
            if root:
                inOrder(root.left)
                res = min(res, root.val - pre)
                pre = root.val
                inOrder(root.right)
                
        inOrder(root)
        return res