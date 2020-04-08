class Solution:
    def longestDiverseString(self, A, B, C, a='a', b='b', c='c'):
        if A < B:
            return self.longestDiverseString(B, A, C, b, a, c)
        if B < C:
            return self.longestDiverseString(A, C, B, a, c, b)
        if B == 0:
            return min(2, A) * a
        na = min(2, A)
        nb = 1 if A - na >= B else 0
        return na * a + nb * b + self.longestDiverseString(A - na, B - nb, C, a, b, c)