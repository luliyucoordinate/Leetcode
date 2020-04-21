class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        n, mod = len(s), 1000000007
        dp = [0] * (n + 1)
        dp[-1] = 1
        
        for i in range(n - 1, -1, -1):
            if s[i] == '0': continue
            cur = 0
            for t in range(1, n - i + 1):
                cur = cur * 10 + ord(s[i + t - 1]) - 48
                if cur > k: break
                dp[i] = (dp[i] + dp[i + t]) % mod
        return dp[0]