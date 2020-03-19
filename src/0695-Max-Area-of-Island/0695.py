class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        d = [0, 1, 0, -1, 0]
        
        def dfs(x, y):
            res = 1
            for i in range(4):
                nx, ny = d[i] + x, d[i + 1] + y
                if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] == 1:
                    grid[nx][ny] = 0
                    res += dfs(nx, ny)
            return res

        res = 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    res = max(res, dfs(i, j))
        return res