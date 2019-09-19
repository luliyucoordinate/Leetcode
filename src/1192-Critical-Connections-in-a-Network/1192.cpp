class Solution 
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        for (auto& it : connections) g[it[0]].emplace_back(it[1]), g[it[1]].emplace_back(it[0]);
        low = vector<int>(n, 0);
        dfs(1);
        return res;
    }
    
    void dfs(int cur, int v=0, int p=-1) 
    {
        int dfn = cur;
        low[v] = cur;
        for (auto i : g[v])
        {
            if (i != p)
            {
                if (low[i] == 0)
                {
                    dfs(++cur, i, v);
                    if (low[i] > dfn) res.push_back({v, i});
                }
                low[v] = min(low[v], low[i]);
            }
        }
    }
private:    
    vector<vector<int>> res;
    vector<int> low;
    unordered_map<int, vector<int>> g;
};