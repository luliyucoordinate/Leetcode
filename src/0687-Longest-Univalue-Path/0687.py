class Solution:
    def longestUnivaluePath(self, root: 'TreeNode') -> 'int':
        res = 0
        def longestUnivalue(root):
            nonlocal res
            if not root:
                return 0
            l = longestUnivalue(root.left)
            r = longestUnivalue(root.right)
            pl, pr = 0, 0
            if root.left and root.left.val == root.val:
                pl = l + 1
            if root.right and root.right.val == root.val:
                pr = r + 1
            res = max(res, pl + pr)
            return max(pl, pr)
            
        longestUnivalue(root)
        return res