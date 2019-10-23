class Solution 
{
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> g;
        vector<int> d(n), vis(n), res;
        for (auto& it : prerequisites)
        {
            g[it[1]].push_back(it[0]); 
            d[it[0]]++;
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
            auto cur = q.front(); q.pop();
            res.push_back(cur);
            n--;
            for (int i : g[cur])
            {
                d[i]--;
                if (!vis[i] and d[i] == 0)
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return n == 0 ? res : vector<int>();
    }
};