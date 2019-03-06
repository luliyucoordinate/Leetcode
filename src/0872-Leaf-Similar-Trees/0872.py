class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def preOrder(node):
            if node:
                if not node.left and not node.right: 
                    yield node.val
                for i in preOrder(node.left): 
                    yield i
                for i in preOrder(node.right): 
                    yield i
        return all(a == b for a, b in itertools.zip_longest(preOrder(root1), preOrder(root2)))