import collections

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root: 
            return 0

        self.result = 0
        freq = collections.defaultdict(int)
        freq[0] = 1
        self.dfs(root, 0, freq, sum)
        return self.result
        
    def dfs(self, node, pathSum, freq, sum):
        if node:
            pathSum += node.val
            self.result += freq[pathSum - sum]
            freq[pathSum] += 1
            
            self.dfs(node.left, pathSum, freq, sum)
            self.dfs(node.right, pathSum, freq, sum)

            freq[pathSum] -= 1