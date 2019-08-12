from functools import lru_cache
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        mod = 10**9 + 7
        
        @lru_cache(None)
        def dfs(m, t):
            if m < 0 or t < 0:
                return 0
            if m == 0 and t == 0:
                return 1
            
            res = 0
            for i in range(1, f + 1):
                res = (res + dfs(m - 1, t - i))%mod
            return res
        return dfs(d, target)