class Solution 
{
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> g(n, vector<int>());
        vector<int> d(n, 0);
        vector<int> vis(n, 0);
        for (auto& p : pre) 
        {
            g[p[1]].push_back(p[0]);
            d[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) 
        {
            if (d[i] == 0) 
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (!q.empty()) 
        {
            int cur = q.front(); q.pop(); n--;
            for (auto i : g[cur])
            {
                if (!vis[i] and --d[i] == 0) 
                {
                    vis[i] = 1;
                    q.push(i);
                }
            } 
        }
        return n == 0;
    }
};