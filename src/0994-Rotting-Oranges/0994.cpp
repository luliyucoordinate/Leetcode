static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    static vector<vector<int>> d;
    
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<vector<int>> rot;
        int r = grid.size(), c = grid[0].size();
        
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 2) rot.push({i, j, 0});
            }
        }
        
        int res = 0;
        while (!rot.empty())
        {
            vector<int> pre = rot.front(); rot.pop();
            res = pre[2];
            for (auto& it : d)
            {
                int x = pre[0] + it[0];
                int y = pre[1] + it[1];
                if (x >= 0 and x < r and y >= 0 and y < c and grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    rot.push({x, y, pre[2] + 1});
                }
            }
        }
        
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 1) return -1;
            }
        }
        return res;
    }

};
vector<vector<int>> Solution::d = {{0,1}, {0,-1}, {1,0}, {-1,0}};