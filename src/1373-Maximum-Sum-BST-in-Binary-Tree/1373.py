class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        maxv = 0
        def dfs(root):
            nonlocal maxv
            if not root: return True, 0
            
            res = [True, root.val]
            if root.left:
                left = dfs(root.left)
                if left[0] and root.left.val < root.val:
                    res[1] += left[1]
                else:
                    res[0] = False
            
            if root.right:
                right = dfs(root.right)
                if right[0] and root.val < root.right.val:
                    res[1] += right[1]
                else:
                    res[0] = False

            if res[0]: maxv = max(maxv, res[1])
            return res
        
        dfs(root)
        return maxv