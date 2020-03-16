class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        res = []
        def inOrder(node):
            if node:
                inOrder(node.left)
                res.append(node.val)
                inOrder(node.right)
        
        inOrder(root)
        
        def sortedToBST(l, r):
            if l > r: return None
            mid = (l + r) >> 1
            root = TreeNode(res[mid])
            root.left = sortedToBST(l, mid - 1)
            root.right = sortedToBST(mid + 1, r)
            return root
        
        return sortedToBST(0, len(res)-1)