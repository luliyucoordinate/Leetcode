class FindElements:
    def __init__(self, root: TreeNode):
        root.val = 0
        def dfs(node):
            if node.left:
                node.left.val = 2*node.val + 1
                dfs(node.left)
            if node.right:
                node.right.val = 2*node.val + 2
                dfs(node.right)
        dfs(root)
        self.root = root
        
    def find(self, target: int) -> bool:
        cur = self.root
        for i in bin(target + 1)[3:]:
            if not cur:
                return False
            if i == '1':
                cur = cur.right
            else:
                cur = cur.left
        return cur != None