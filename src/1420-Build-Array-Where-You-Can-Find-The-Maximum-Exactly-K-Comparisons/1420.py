class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        mod = 10**9 + 7

        dp = [[[0] * (m + 1) for _ in range(k + 1)] for _ in range(n + 1)]
        for c in range(m + 1):
            dp[1][1][c] = c
        for a in range(2, n + 1):
            for b in range(1, k + 1):
                for c in range(b, m + 1):
                    dp[a][b][c] = (dp[a][b][c - 1] + dp[a - 1][b - 1][c - 1] + \
                                   (dp[a - 1][b][c] - dp[a - 1][b][c - 1] + mod) * c) % mod
        return dp[-1][-1][-1]