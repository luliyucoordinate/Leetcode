class Solution:
    def rotatedDigits(self, N: int) -> int:
        s1 = set([0, 1, 8])
        s2 = set([0, 1, 8, 2, 5, 6, 9])
        s = set()
        res = 0
        N = list(map(int, str(N+1)))
        for i, v in enumerate(N):
            for j in range(v):
                if s.issubset(s2) and j in s2:
                    res += 7**(len(N) - i - 1)
                if s.issubset(s1) and j in s1:
                    res -= 3**(len(N) - i - 1)
            if v not in s2:
                return res
            s.add(v)
        return res