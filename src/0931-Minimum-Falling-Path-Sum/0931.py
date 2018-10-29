class Solution:
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        if not A:
            return 0

        r, c = len(A), len(A[0])
        for row in range(r - 1, 0, -1):
            for col in range(c):
                if col == 0:
                    A[row - 1][col] += min(A[row][col], A[row][col + 1])
                elif col == c - 1:
                    A[row - 1][col] += min(A[row][col], A[row][col - 1])
                else:
                    A[row - 1][col] += min(A[row][col], A[row][col + 1], A[row][col - 1])

        return min(A[0])

if __name__ == "__main__":
    A = [[-19,57],[-40,-5]]
    print(Solution().minFallingPathSum(A))