class Solution:
    def removeCoveredIntervals(self, A: List[List[int]]) -> int:
        res = r = 0
        for _, j in sorted(A, key=lambda a: [a[0], -a[1]]):
            res += j > r
            r = max(r, j)
        return res