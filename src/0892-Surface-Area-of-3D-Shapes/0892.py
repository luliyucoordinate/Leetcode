class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res, r, c = 0, len(grid), len(grid[0])
        for i in range(r):
            for j in range(c):
                if grid[i][j]: res += grid[i][j] * 4 + 2
                if i: res -= min(grid[i - 1][j], grid[i][j]) * 2
                if j: res -= min(grid[i][j - 1], grid[i][j]) * 2
        return res