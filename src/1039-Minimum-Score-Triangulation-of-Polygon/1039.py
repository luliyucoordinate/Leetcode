class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        n = len(A)
        dp = [[0] * n for i in range(n)]
        for d in range(2, n):
            for i in range(n - d):
                j = i + d
                dp[i][j] = min(dp[i][k] + dp[k][j] + A[i] * A[j] * A[k] for k in range(i + 1, j))
        return dp[0][n - 1]