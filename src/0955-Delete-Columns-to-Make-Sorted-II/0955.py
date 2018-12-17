class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        res, n, m = 0, len(A), len(A[0])
        unsorted = set(range(n - 1))
        for j in range(m):
            if any(A[i][j] > A[i + 1][j] for i in unsorted):
                res += 1
            else:
                unsorted -= {i for i in unsorted if A[i][j] < A[i + 1][j]}
        return res