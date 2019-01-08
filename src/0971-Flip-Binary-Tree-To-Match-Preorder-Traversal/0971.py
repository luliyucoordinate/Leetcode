class Solution:
    def flipMatchVoyage(self, root, voyage):
        """
        :type root: TreeNode
        :type voyage: List[int]
        :rtype: List[int]
        """
        res = list()
        i = 0
        def dfs(root):
            nonlocal i
            if not root:
                return True
            
            if root.val != voyage[i]:
                return False
            
            i += 1
            if root.left and root.left.val != voyage[i]:
                res.append(root.val)
                root.left, root.right = root.right, root.left
                
            return dfs(root.left) and dfs(root.right)
        
        return res if dfs(root) else [-1]