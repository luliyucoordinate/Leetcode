class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        res = list()
        to_delete = set(to_delete)
        
        def preOrder(root, n_root):
            if root:
                root_delete = root.val in to_delete
                if not root_delete and n_root:
                    res.append(root)
                root.left = preOrder(root.left, root_delete)
                root.right = preOrder(root.right, root_delete)
                return None if root_delete else root
            
        preOrder(root, True)
        return res