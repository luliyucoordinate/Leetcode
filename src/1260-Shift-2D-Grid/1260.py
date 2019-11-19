class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        res = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                t = j + k
                res[(i + t//m)%n][t % m] = grid[i][j]
        return res