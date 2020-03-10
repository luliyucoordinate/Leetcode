class Solution 
{
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        if (n == 1) return 1;
        
        g.resize(n + 1);
        this->target = target;
        for (auto& it : edges)
        {
            g[it[0]].emplace_back(it[1]);
            g[it[1]].emplace_back(it[0]);
        }
        return dfs(-1, 1, t);
    }
private:
    vector<vector<int>> g;
    int target;
    
    double dfs(int fa, int cur, int t)
    {
        if (cur != 1 && g[cur].size() == 1 || t == 0) return cur == target;
        
        double res = 0.0;
        for (int i : g[cur])
        {
            if (i != fa) res = max(res, dfs(cur, i, t - 1));
        }
        return res / (g[cur].size() - (cur != 1));
    }
};