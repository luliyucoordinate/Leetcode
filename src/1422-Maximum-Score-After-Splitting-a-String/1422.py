class Solution:
    def maxScore(self, s: str) -> int:
        zeros, ones, res, n = 0, 0, float("-inf"), len(s)
        for i in range(n):
            if s[i] == '1': ones += 1
            else: zeros += 1
            if i != n - 1: res = max(res, zeros - ones)
        return res + ones