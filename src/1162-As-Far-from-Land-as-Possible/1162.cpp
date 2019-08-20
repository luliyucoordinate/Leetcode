class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> data;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]) data.emplace(i, j);
            }   
        }
            

        if (n * m == data.size() or 0 == data.size()) return -1;
        
        int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int res = 0;
        while (!data.empty()) 
        {
            int dataLen = data.size();
            for (int i = 0; i < dataLen; i++) 
            {
                auto [u, v] = data.front();
                data.pop();
                for (auto [xd, yd] : d) 
                {
                    int x = u + xd, y = v + yd;
                    if (x < 0 or x >= n or y < 0 or y >= m or grid[x][y]) continue;
                    grid[x][y] = 1;
                    data.emplace(x, y);
                }
            }
            res++;
        }
        return res - 1;
    }
};