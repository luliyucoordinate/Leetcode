class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        def find(root, t):
            if not root:
                return False
            if root.val == t:
                return True
            elif root.val < t:
                return find(root.right, t)
            else:
                return find(root.left, t)
        
        if not root1:
            return False
        if find(root2, target - root1.val):
            return True
        return self.twoSumBSTs(root1.left, root2, target) or \
            self.twoSumBSTs(root1.right, root2, target)