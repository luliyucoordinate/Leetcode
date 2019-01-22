class Solution:
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        start, end, p = None, None, 1
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    start = i, j
                elif grid[i][j] == 2:
                    end = i, j
                elif grid[i][j] == 0:
                    p += 1
                    
        def dfs(x, y, p):
            if not (0 <= x < row and 0 <= y < col and grid[x][y] >= 0):
                return 0
            if end == (x, y) and p == 0:
                return 1
            grid[x][y] = -1
            res = dfs(x+1, y, p-1) + dfs(x, y+1, p-1) + dfs(x-1, y, p-1) + dfs(x, y-1, p-1)
            grid[x][y] = 0
            return res
        
        return dfs(start[0], start[1], p)