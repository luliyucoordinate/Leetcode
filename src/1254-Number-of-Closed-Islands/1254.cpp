class Solution 
{
public:
    int closedIsland(vector<vector<int>>& g) 
    {
        int r = g.size(), c = g[0].size(), res = 2;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (g[i][j] == 0) 
                {
                    dfs(i, j, res++, g);
                }                
            }
        }
        unordered_set<int> color = {0, 1};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == 0 || i == r - 1) color.emplace(g[i][j]);
                else if (j == 0 || j == c - 1) color.emplace(g[i][j]);
            }
        }
        return res - color.size();
    }
private:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int check(int i, int j, vector<vector<int>>& g) 
    {
        return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : 1;
    }
    
    void dfs(int i, int j, int color, vector<vector<int>>& g)
    {
        if (!check(i, j, g) || g[i][j] != 0) return;
        g[i][j] = color;
        for (int x = 0; x < 4; x++)
            dfs(dire[x][0] + i, dire[x][1] + j, color, g);
    }
};