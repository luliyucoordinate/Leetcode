class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        def lcs(x, y):
            l = [[0]*(n + 1) for _ in range(n + 1)]
            for i in range(1, n + 1):
                for j in range(1, n + 1):
                    if x[i-1] == y[j-1]:
                        l[i][j] = l[i-1][j-1] + 1
                    else:
                        l[i][j] = max(l[i-1][j], l[i][j-1])
            return l[-1][-1]
        return n - lcs(s, s[::-1]) <= k