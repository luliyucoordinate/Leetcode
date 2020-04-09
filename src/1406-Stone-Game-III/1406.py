class Solution:
    def stoneGameIII(self, A: List[int]) -> str:
        dp, n, sum_all = [0] * 3, len(A), 0
        for i in range(n - 1, -1, -1):
            sum_all += A[i]
            dp[i % 3] = sum_all - min(dp[(i + k) % 3] for k in range(1, 4))
        
        if dp[0] * 2 == sum_all: return "Tie"
        return "Alice" if dp[0] * 2 > sum_all else "Bob"