class Solution 
{
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        n = workers.size(), m = bikes.size();
        int k = 1 << m;
        vector<vector<int>> f(n, vector<int>(k, -1));
        return dfs(0, 0, workers, bikes, f);
    }

private:
    int n, m;
    int dis(vector<int>& a, vector<int>& b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    int dfs(int i, int j, vector<vector<int>>& workers, vector<vector<int>>& bikes, vector<vector<int>>& f)
    {
        if(i == n) return 0;
        if(~f[i][j]) return f[i][j];
        f[i][j] = INT_MAX;
        for(int k = 0; k < m; ++k) 
        {
            if(!(j & (1 << k)))
                f[i][j] = min(f[i][j], dfs(i+1, j | (1 << k), workers, bikes, f) + dis(workers[i], bikes[k]));
        }
        return f[i][j];
    }
};