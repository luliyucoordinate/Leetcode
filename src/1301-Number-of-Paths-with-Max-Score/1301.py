class Solution:
    def pathsWithMaxScore(self, A):
        n, mod = len(A), 10**9 + 7
        dp = [[[-10**5, 0] for _ in range(n + 1)] for _ in range(n + 1)]
        dp[n - 1][n - 1] = [0, 1]
        
        for x in range(n-1, -1, -1):
            for y in range(n-1, -1, -1):
                if A[x][y] in 'XS': 
                    continue
                    
                for i, j in [[0, 1], [1, 0], [1, 1]]:
                    if dp[x][y][0] < dp[x + i][y + j][0]:
                        dp[x][y] = [dp[x + i][y + j][0], 0]
                    if dp[x][y][0] == dp[x + i][y + j][0]:
                        dp[x][y][1] += dp[x + i][y + j][1]
                dp[x][y][0] += int(A[x][y]) if x or y else 0
                
        return [dp[0][0][0] if dp[0][0][1] else 0, dp[0][0][1] % mod]