class Solution 
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) 
    {
        vector<map<int, vector<int>>> g(2, map<int, vector<int>>());
        for (auto& d : red_edges) g[0][d[0]].push_back(d[1]);
        for (auto& d : blue_edges) g[1][d[0]].push_back(d[1]);
        vector<int> res(n, INT_MAX);
        
        queue<vector<int>> q;
        q.push({0, 0, 0}); q.push({0, 1, 0});
        unordered_set<int> vis;
        vis.insert(0); vis.insert(1);
        
        while (!q.empty())
        {
            auto pre = q.front(); q.pop();
            res[pre[0]] = min(res[pre[0]], pre[2]);
            int nc = 1 - pre[1];
            for (auto& nd : g[nc][pre[0]])
            {
                int key = nd * 401 + nc;
                if (!vis.count(key))
                {
                    q.push({nd, nc, pre[2] + 1});
                    vis.insert(key);
                }
            }
        }
        for (int i = 0; i < n; ++i) if (res[i] == INT_MAX) res[i] = -1;
        return res;
    }
};