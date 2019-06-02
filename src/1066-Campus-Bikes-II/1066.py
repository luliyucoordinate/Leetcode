class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        def dis(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])
        
        n, m = len(workers), len(bikes)
        f = [[-1]*(1 << m) for _ in range(n)]
        
        def dfs(i, j):
            nonlocal f
            if i == n:
                return 0
            
            if f[i][j] != -1:
                return f[i][j]
            
            f[i][j] = float("inf")
            for k in range(m):
                if not (j >> k & 1):
                    f[i][j] = min(f[i][j], dfs(i + 1, j | (1 << k)) + dis(workers[i], bikes[k]))
            return f[i][j]
                
        return dfs(0, 0)