class Solution 
{
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) 
    {
        vector<vector<int>> g(N);
        vector<int> degrees(N, 0);
        for (auto& e : relations) g[--e[0]].push_back(--e[1]), degrees[e[1]]++;

        int num = 0, res = 0;
        queue<int> q;
        for(int i = 0; i < N; i ++) if (degrees[i] == 0) q.push(i), num++;
        
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                int v = q.front(); q.pop();
                for(int w : g[v])
                {
                    degrees[w]--;
                    if (!degrees[w]) q.push(w), num ++;
                }
            } 
            res++;
        }
        return num == N ? res : -1;
    }
};