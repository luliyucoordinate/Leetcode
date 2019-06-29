class Solution 
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        vector<int> res(N);
        vector<vector<int>> m(N + 1);
        for (auto& it : paths) 
        {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }
        
        for (int i = 1; i <= N; ++i) 
        {
            bool used[5] = {};
            for (auto& it : m[i]) used[res[it - 1]] = true;
            
            for (int c = 1; c <= 4; ++c) 
            {
                if (!used[c]) 
                {
                    res[i - 1] = c; break;
                }
            }
        }
        return res;
    }
};