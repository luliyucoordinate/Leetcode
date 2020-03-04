typedef pair<int, int> PII;
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        int d[5] = {0, 1, 0, -1, 0};
        int step = 0, cnt = 0;
        queue<PII> q;
        
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1) cnt++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        
        while (!q.empty())
        {
            if (cnt == 0) return step;
            
            int n = q.size();
            while (n--)
            {
                auto t = q.front(); q.pop();
                int x = t.first, y = t.second;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + d[i], ny = y + d[i + 1];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1)
                    {
                        cnt--;
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            step++;
        }
        
        return cnt == 0 ? step : -1;
    }
};