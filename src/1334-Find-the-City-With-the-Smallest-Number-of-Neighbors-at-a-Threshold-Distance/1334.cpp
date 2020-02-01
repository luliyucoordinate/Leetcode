class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int d[n][n];
        memset(d, 0x3f, sizeof d);
        
        for (int i = 0; i < n; i++) d[i][i] = 0;
        for (auto& it : edges) d[it[0]][it[1]] = d[it[1]][it[0]] = it[2];
        
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        int smallest = INT_MAX, res = 0;
        for (int i = 0; i < n; i++) 
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j) if (d[i][j] <= distanceThreshold) ++cnt;
            if (cnt <= smallest) res = i, smallest = cnt;
        }
        return res;
    }
};