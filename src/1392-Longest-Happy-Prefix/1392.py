class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        f = [0] * (n + 1)
        f[0], i, j = -1, 0, -1
        
        while i < n:
            while j != -1 and s[i] != s[j]:
                j = f[j]
            i += 1
            j += 1
            f[i] = j
        return s[:f[-1]]