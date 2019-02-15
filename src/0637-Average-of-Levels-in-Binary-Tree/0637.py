class Solution:
    def averageOfLevels(self, root: 'TreeNode') -> 'List[float]':
        res = list()
        cur, n = [root], list()
        while cur:
            tmp = 0
            for node in cur:
                tmp += node.val
                if node.left:
                    n.append(node.left)
                if node.right:
                    n.append(node.right)
            res.append(tmp/len(cur))
            cur = n.copy()
            n.clear()
            
        return res
                