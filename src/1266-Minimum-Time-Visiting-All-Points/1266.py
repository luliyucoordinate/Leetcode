class Solution:
    def minTimeToVisitAllPoints(self, p: List[List[int]]) -> int:
        return sum(max(abs(p[i][0] - p[i - 1][0]), abs(p[i][1] - p[i - 1][1])) for i in range(1, len(p)))