class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        d = [0] * n
        for i in leftChild + rightChild:
            if i != -1: d[i] += 1
        
        root = -1
        for i in range(n):
            if d[i] == 0:
                if root != -1: return False
                root = i

        if root == -1: return False
        
        vis, q = set([root]), [root]
        while q:
            pre = q.pop(0)
            if leftChild[pre] != -1:
                if leftChild[pre] in vis: return False
                vis.add(leftChild[pre])
                q.append(leftChild[pre])
            
            if rightChild[pre] != -1:
                if rightChild[pre] in vis: return False
                vis.add(rightChild[pre])
                q.append(rightChild[pre])
        
        return len(vis) == n