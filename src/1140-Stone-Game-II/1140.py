from functools import lru_cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        for i in range(n - 2, -1, -1):
            piles[i] += piles[i + 1]

        @lru_cache(None)
        def dfs(i, m):
            if i + 2 * m >= n: 
                return piles[i]
            return piles[i] - min(dfs(i + x, max(m, x)) for x in range(1, 2 * m + 1))
        return dfs(0, 1)