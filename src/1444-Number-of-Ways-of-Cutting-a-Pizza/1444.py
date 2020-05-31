from functools import lru_cache
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        mod = 10**9 + 7
        r, c = len(pizza), len(pizza[0])
        g = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(r-1, -1, -1):
            for j in range(c-1, -1, -1):
                g[i][j] = g[i+1][j] + g[i][j+1] - g[i+1][j+1] + (pizza[i][j] == 'A')

        @lru_cache(None)
        def dfs(i, j, t):
            if g[i][j] == 0: return 0
            if t == 0: return 1
            
            res = 0
            for x in range(i + 1, r):
                if g[i][j] - g[x][j] > 0:
                    res += dfs(x, j, t - 1)
            for y in range(j + 1, c):
                if g[i][j] - g[i][y] > 0:
                    res += dfs(i, y, t - 1)
            return res % mod
        return dfs(0, 0, k - 1)