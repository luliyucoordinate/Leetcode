class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
            
        res = 0
        r, c = len(grid), len(grid[0])
        d = [0, 1, 0, -1, 0]
        def dfs(x, y):
            for i in range(4):
                nx, ny = x + d[i], y + d[i + 1]
                if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] == '1':
                    grid[nx][ny] = '0'
                    dfs(nx, ny)

        for i, row in enumerate(grid):
            for j, _ in enumerate(row):
                if grid[i][j] == '1':
                    res += 1
                    grid[i][j] = '0'
                    dfs(i, j)
        return res