class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        q, maxSum, res, level = [root], 0, 0, 0
        while any(q):
            curSum = 0
            for _ in range(len(q)):
                node = q.pop(0)
                curSum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level += 1
            if curSum > maxSum:
                maxSum, res = curSum, level
        return res