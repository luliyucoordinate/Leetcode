class Solution:
    def countSquares(self, A: List[List[int]]) -> int:
        res = 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if i and j and A[i][j]:
                    A[i][j] = min(A[i - 1][j], A[i][j - 1], A[i - 1][j - 1]) + 1
                res += A[i][j]
        return res