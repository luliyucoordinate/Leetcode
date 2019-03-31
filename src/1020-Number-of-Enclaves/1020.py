class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and A[i][j] == 1:
                A[i][j] = 0
                list(map(dfs, (i+1, i-1, i, i), (j, j, j+1, j-1)))

        m, n = len(A), len(A[0])
        for i in range(m):
            list(map(dfs, (i, i), (0, n - 1)))

        for i in range(n):
            list(map(dfs, (0, m - 1), (i, i)))
            
        return sum(sum(row) for row in A)