class Solution 
{
public:
    string shortestSuperstring(vector<string>& A) 
    {
        int n = A.size(), vis = (1 << n) - 1;
        int dp[1 << n][n], path[1 << n][n], g[n][n];
        memset(dp, 0x3f, sizeof dp);
        memset(g, 0, sizeof g);
        memset(path, 0, sizeof path);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                g[i][j] = dis(A[i], A[j]);
            }
        }
        
        int best = 300, pos = -1, pre, p;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (((i >> j) & 1) == 0) continue;
                
                pre = i - (1 << j);
                if (pre == 0) dp[i][j] = A[j].size();
                else
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (((pre >> k) & 1) == 0) continue;
                        
                        p = dp[pre][k] + g[k][j];
                        if (dp[i][j] > p)
                        {
                            dp[i][j] = p, path[i][j] = k;
                        }
                    }
                }
                
                if (i == vis && best > dp[i][j])
                {
                    best = dp[i][j], pos = j;
                }
            }
        }
        
        string res = A[pos];
        int t = vis;
        while (true)
        {
            pre = path[t][pos];
            t -= (1 << pos);
            if (t == 0) break;
            res = A[pre] + res.substr(A[pos].size() - g[pre][pos]);
            pos = pre;
        }
        return res;
    }
    
private:
    int dis(string& a, string& b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a.size() - i <= b.size() && 
                a.substr(i) == b.substr(0, a.size() - i))
                return b.size() - a.size() + i;
        }
        return b.size();
    }
};