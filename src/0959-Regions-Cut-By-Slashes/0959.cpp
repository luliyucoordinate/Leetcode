static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int regionsBySlashes(vector<string>& grid, int regions = 0) 
    {
        vector<vector<int>> g(grid.size() * 3, vector<int>(grid.size() * 3, 0));
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid.size(); ++j) 
            {
                if (grid[i][j] == '/') g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
                if (grid[i][j] == '\\') g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }          
        }

        for (auto i = 0; i < g.size(); ++i)
        for (auto j = 0; j < g.size(); ++j) if (g[i][j] == 0) dfs(g, i, j), ++regions;
        return regions;
    }
private:
    void dfs(vector<vector<int>>& g, int i, int j) 
    {
        if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0) 
        {
            g[i][j] = 1;
            dfs(g, i - 1, j), dfs(g, i + 1, j), dfs(g, i, j - 1), dfs(g, i, j + 1);
        }
    }
};