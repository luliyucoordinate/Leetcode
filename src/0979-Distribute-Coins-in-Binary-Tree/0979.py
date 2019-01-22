class Solution:
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        self.dfs(root)
        return self.res
        
    def dfs(self, root):
        if root:
            l, r = self.dfs(root.left), self.dfs(root.right)
            self.res += abs(l) + abs(r)
            return l + r + root.val - 1
        return 0