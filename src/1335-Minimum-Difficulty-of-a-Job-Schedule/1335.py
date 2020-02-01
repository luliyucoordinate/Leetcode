from functools import lru_cache
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        
        @lru_cache(None)
        def dfs(u, d):
            if d == 1:
                return max(jobDifficulty[u:])
            
            res, m = float("inf"), 0
            for i in range(u, n - d + 1):
                m = max(m, jobDifficulty[i])
                res = min(res, dfs(i + 1, d - 1) + m)
            return res
        
        return dfs(0, d)