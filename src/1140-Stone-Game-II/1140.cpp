class Solution 
{
public:
    int stoneGameII(vector<int>& piles) 
    {
        n = piles.size();
        for (int i = n - 2; i >= 0; --i)
        {
            piles[i] += piles[i+1];
        }
        mem = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        return dfs(0, 1, piles);
    }
    
    vector<vector<int>> mem;
    int n;
    int dfs(int i, int m, vector<int>& piles)
    {
        if (mem[i][m] != INT_MAX) return mem[i][m];
        if (i + 2 * m >= n) return piles[i];
        int res = INT_MIN;
        for (int x = 1; x <= 2 * m; ++x)
        {
            res = max(res, piles[i] - dfs(i + x, max(x, m), piles));
        }
        mem[i][m] = res;
        return res;
    }
};