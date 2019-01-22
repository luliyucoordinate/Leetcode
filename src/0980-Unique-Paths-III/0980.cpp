static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int i1 = 0, j1 = 0, t_steps = 1;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j) 
            {
                if (grid[i][j] == 1) i1 = i, j1 = j;
                if (grid[i][j] == 0) ++t_steps;
            }            
        }
        return dfs(grid, i1, j1, t_steps);
    }
private:
    int dfs(vector<vector<int>>& g, int i, int j, int s) 
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
        if (g[i][j] == 2) return s == 0 ? 1 : 0;
        g[i][j] = -1;
        int paths = dfs(g, i + 1, j, s - 1) + dfs(g, i - 1, j, s - 1) +
        dfs(g, i, j + 1, s - 1) + dfs(g, i, j - 1, s - 1);
        g[i][j] = 0;
        return paths;
    }
};