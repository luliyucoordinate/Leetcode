class Solution 
{
public:
    int treeDiameter(vector<vector<int>>& edges) 
    {
        for (auto& it : edges) 
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs(0, -1);
        return res;
    }

private:
    unordered_map<int, vector<int>> g;
    int res;
    
    int dfs(int cur, int pre)
    {
        int d1 = 0, d2 = 0;
        for (int i : g[cur])
        {
            if (i != pre)
            {
                int d = dfs(i, cur);
                if (d > d1) 
                {
                    int tmp = d1;
                    d1 = d, d2 = tmp;
                }
                else if (d > d2) d2 = d;
            }
        }
        res = max(res, d1 + d2);
        return d1 + 1;
    }
};