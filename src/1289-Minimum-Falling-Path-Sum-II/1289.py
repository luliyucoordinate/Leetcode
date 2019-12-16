class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        r, c = len(A), len(A[0])
        for i in range(1, r):
            r = heapq.nsmallest(2, A[i - 1])
            for j in range(c):
                A[i][j] += r[1] if A[i - 1][j] == r[0] else r[0]
        return min(A[-1])