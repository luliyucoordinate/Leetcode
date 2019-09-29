class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        i, n = -1, len(s)
        d = [abs(ord(s[i]) - ord(t[i])) for i in range(n)]
        for j in range(n):
            maxCost -= d[j]
            if maxCost < 0:
                i += 1
                maxCost += d[i]
        return j - i