from functools import lru_cache
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        @lru_cache(None)
        def dfs(l, r):
            if l > r:
                return 0
            res = 1 + dfs(l + 1, r)
            for i in range(l + 1, r + 1):
                if arr[i] == arr[l]:
                    res = min(res, dfs(l + 1, i - 1) + dfs(i + 1, r) + (l + 1 == i)) 
            return res
        return dfs(0, len(arr) - 1)