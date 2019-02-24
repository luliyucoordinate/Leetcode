class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        if root.val < val:
            tmp = TreeNode(val)
            tmp.left = root
            return tmp
        
        if root.right:
            root.right = self.insertIntoMaxTree(root.right, val)
        else:
            tmp = TreeNode(val)
            root.right = tmp
        return root