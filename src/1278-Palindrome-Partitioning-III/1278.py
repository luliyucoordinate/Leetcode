class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        p = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j - 1, -1, -1):
                p[i][j] = 0 if s[i] == s[j] else 1
                if i + 1 < j:
                    p[i][j] += p[i+1][j-1]

        f = [[float("inf")]*n for _ in range(k + 1)]
        for i in range(n):
            f[1][i] = p[0][i]
            
        for i in range(2, k + 1):
            for r in range(i - 1, n):
                for l in range(i - 2, r):
                    f[i][r] = min(f[i][r], p[l + 1][r] + f[i - 1][l])
        return f[k][n-1]