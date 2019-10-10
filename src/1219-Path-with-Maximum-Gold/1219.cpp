class Solution 
{
public:
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        g = grid, m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j]) res = max(res, g[i][j] + dfs(i, j));    
            }
        }
        return res;
    }
    
private:
    vector<vector<int>> g;
    int m, n;
    vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int dfs(int x, int y)
    {
        int res = 0, src = g[x][y];
        g[x][y] = 0;
        for (auto& it : d)
        {
            int nx = it[0] + x, ny = it[1] + y;
            if (nx >= 0 and nx < m and ny >= 0 and ny < n and g[nx][ny])
                res = max(res, g[nx][ny] + dfs(nx, ny));
        }
        g[x][y] = src;
        return res;
    }
};