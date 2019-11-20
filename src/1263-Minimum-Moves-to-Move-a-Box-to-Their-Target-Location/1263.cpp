typedef pair<int, int> PII;
class Solution 
{
public:
    int minPushBox(vector<vector<char>>& grid) 
    {
        r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 'T') T = {i, j};
                else if (grid[i][j] == 'S') S = {i, j};
                else if (grid[i][j] == 'B') B = {i, j};
            }
        }
        
        int res = 0;
        queue<vector<int>> q;
        q.push({B.first, B.second, S.first, S.second});
        int vis[21][21][21][21] = {};
        vis[B.first][B.second][S.first][S.second] = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                auto p = q.front(); q.pop();
                if (p[0] == T.first && p[1] == T.second) return res;

                for (auto& it : dire)
                {
                    int nx = it[0] + p[0], ny = it[1] + p[1];
                    PII e = {p[0] - it[0], p[1] - it[1]}, b = {p[0], p[1]}, s = {p[2], p[3]};
                    if (check(nx, ny, grid) && check(e.first, e.second, grid) &&
                       !vis[nx][ny][p[0]][p[1]] && canMoveTo(e, b, s, grid))
                    {
                        q.push({nx, ny, p[0], p[1]});
                        vis[nx][ny][p[0]][p[1]] = 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
private:
    int r, c;
    PII S, B, T;
    
    int dire[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    
    bool check(int x, int y, vector<vector<char>>& grid)
    {
        return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#';
    }
    
    bool canMoveTo(PII& e, PII& b, PII& s, vector<vector<char>>& grid)
    {
        queue<PII> q; q.push(s);
        int vis[21][21] = {};
        vis[s.first][s.second] = 1;
        while (!q.empty())
        {
            auto pre = q.front(); q.pop();
            if (pre.first == e.first && pre.second == e.second) return true;

            for (auto& it : dire)
            {
                int nx = pre.first + it[0], ny = pre.second + it[1];
                if (check(nx, ny, grid) && 
                    (nx != b.first || ny != b.second) && !vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};