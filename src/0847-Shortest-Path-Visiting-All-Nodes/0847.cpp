class Solution 
{
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        int t = (1 << n) - 1, res = 0;
        int mem[n][1 << n] = {};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) q.push({i, 1 << i});
        while (true)
        {
            int nq = q.size();
            for (int i = 0; i < nq; i++)
            {
                auto pre = q.front(); q.pop();
                if (pre.second == t) return res;
                for (auto j : graph[pre.first])
                {
                    int new_stat = pre.second | 1 << j;
                    if (!mem[j][new_stat])
                    {
                        q.push({j, new_stat});
                        mem[j][new_stat] = 1;
                    }
                }
            }
            res++;
        }
    }
};