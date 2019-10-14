class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        Max, mod = max(rollMax), 10**9 + 7
        dp = [[0, 1] + [0]*(Max - 1) for i in range(6)]
        tmp, Sum = [1] * 6, 6
        for i in range(1, n):
            ts = 0
            for j in range(6):
                dp[j][0], tmp[j] = (Sum - tmp[j]) % mod, 0
                for k in range(rollMax[j], 0, -1):
                    dp[j][k] = dp[j][k - 1]
                    tmp[j] += dp[j][k]
                ts += tmp[j]
            Sum = ts % mod
        return Sum