class Solution:
    def findCircleNum(self, M: 'List[List[int]]') -> 'int':
        n = len(M)
        visited = [0]*n
        res = 0
        
        def dfs(i):
            for j in range(n):
                if M[i][j] and visited[j] == 0:
                    visited[j] = 1
                    dfs(j)
                
        for i in range(n):
            if visited[i] == 0:
                dfs(i)
                res += 1
                
        return res