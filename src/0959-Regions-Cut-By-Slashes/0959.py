class Solution:
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        grid_len = len(grid)
        g_len = grid_len*3
        g = [[0]*g_len for _ in range(g_len)]
        def dfs(g, i, j):
            if i >= 0 and j >= 0 and i < g_len and j < g_len and g[i][j] == 0:
                g[i][j] = 1
                dfs(g, i - 1, j)
                dfs(g, i + 1, j)
                dfs(g, i, j - 1)
                dfs(g, i, j + 1)
            
        for i in range(grid_len):
            for j in range(grid_len):
                if grid[i][j] == '/':
                    g[i*3+2][j*3], g[i*3+1][j*3+1], g[i*3][j*3+2] = 1, 1, 1
                if grid[i][j] == '\\':
                    g[i*3][j*3], g[i*3+1][j*3+1], g[i*3+2][j*3+2] = 1, 1, 1
                    
        res = 0
        for i in range(g_len):
            for j in range(g_len):
                if g[i][j] == 0:
                    dfs(g, i, j)
                    res += 1
                
        return res