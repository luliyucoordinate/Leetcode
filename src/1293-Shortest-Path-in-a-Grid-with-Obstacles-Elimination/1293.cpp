class Solution 
{
public:
    int shortestPath(vector<vector<int>>& g, int k) 
    {
        int r = g.size(), c = g[0].size();
        if (k >= r + c - 3) return r + c - 2;
        
        int mem[r][c], step = 0;
        memset(mem, 0x3f, sizeof mem);
        queue<vector<int>> q;
        q.push({0, 0, 0});
        mem[0][0] = 0;
        
        while (!q.empty())
        {
            for (int n = q.size(); n > 0; n--)
            {
                auto pre = q.front(); q.pop();
                if (pre[2] > k) continue;
                if (pre[0] == r - 1 && pre[1] == c- 1) return step;
                
                for (int i = 0; i < 4; i++)
                {
                    int nx = pre[0] + d[i], ny = pre[1] + d[i+1];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c)
                    {
                        int nPre = g[nx][ny] == 1 ? pre[2] + 1 : pre[2];
                        if (nPre < mem[nx][ny])
                        {
                            q.push({nx, ny, nPre});
                            mem[nx][ny] = nPre;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
private:
    int d[5] = {0, 1, 0, -1, 0};
};