class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        x, y, n = 0, 0, len(s1)
        for i in range(n):
            if s1[i] != s2[i]:
                if s1[i] == "x":
                    x += 1
                else:
                    y += 1
                
        if (x + y) & 1:
            return -1
        return x // 2 + y // 2 + 2 * (x % 2)