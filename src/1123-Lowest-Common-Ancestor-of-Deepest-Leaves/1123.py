class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root:
                return 0, None
            l, r = dfs(root.left), dfs(root.right)
            if l[0] < r[0]:
                return r[0] + 1, r[1]
            elif l[0] > r[0]:
                return l[0] + 1, l[1]
            else:
                return l[0] + 1, root
            
        return dfs(root)[1]