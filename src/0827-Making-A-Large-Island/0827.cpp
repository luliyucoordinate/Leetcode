class Solution 
{
public:
    int largestIsland(vector<vector<int>>& g) 
    {
        vector<int> data = {0, 0}; 
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 1) data.push_back(dfs(i, j, data.size(), g));
        
        int res = 0;
        for (auto i = 0; i < g.size(); ++i)
        {
            for (auto j = 0; j < g[i].size(); ++j)
            {
                if (g[i][j] == 0) 
                {
                    unordered_set<int> s = {check(i + 1, j, g), check(i - 1, j, g), check(i, j + 1, g), check(i, j - 1, g)};
                    res = max(res, 1 + accumulate(begin(s), end(s), 0, [&](int a, int b) {
                        return a + data[b]; 
                    }));
                }                
            }
        }
        return res == 0 ? g.size() * g[0].size() : res;
    }
private:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int check(int i, int j, vector<vector<int>>& g) 
    {
        return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
    }
    
    int dfs(int i, int j, int color, vector<vector<int>>& g)
    {
        if (check(i, j, g) != 1) return 0;
        g[i][j] = color;
        int res = 1;
        for (int x = 0; x < 4; x++)
        {
            res += dfs(dire[x][0] + i, dire[x][1] + j, color, g);
        }
        return res;
    }
};