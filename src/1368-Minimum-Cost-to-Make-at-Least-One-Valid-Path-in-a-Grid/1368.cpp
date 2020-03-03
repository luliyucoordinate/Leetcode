typedef pair<int, int> PII;
class Solution 
{
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        deque<PII> q = {{0, 0}};
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int vis[m * n] = {};
        int dist[m][n];
        memset(dist, 0x3f, sizeof dist);
        dist[0][0] = 0;
        
        while (!q.empty())
        {
            auto x = q.front(); q.pop_front();
            int step = x.first, pos = x.second;
            if (vis[pos]) continue;
            vis[pos] = 1;
            
            for (int i = 1; i <= 4; i++)
            {
                int x = pos / n, y = pos % n;
                int nx = x + dx[i - 1], ny = y + dy[i - 1];
                int new_dist = step + (grid[x][y] != i);
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > new_dist)
                {
                    dist[nx][ny] = new_dist;
                    if (grid[x][y] != i) q.push_back({dist[nx][ny], nx * n + ny});
                    else q.push_front({dist[nx][ny], nx * n + ny});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};