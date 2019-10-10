class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def dfs(x, y):
            res = 0
            src = grid[x][y]
            grid[x][y] = 0
            for i, j in d:
                nx = i + x
                ny = j + y
                if nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] != 0:
                    res = max(res, grid[nx][ny] + dfs(nx, ny))
            grid[x][y] = src
            return res
        
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    res = max(res, grid[i][j] + dfs(i, j))
        return res