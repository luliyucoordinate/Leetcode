class Solution 
{
public:
    int numWays(int steps, int arrLen) 
    {
        int m = steps, n = min(steps/2+1, arrLen), mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i < m + 1; i++)
        {
            vector<int> dp2(n + 1, 0);
            for (int j = 0; j < n; j++)
            {
                dp2[j] = (dp2[j] + dp[j]) % mod;
                dp2[j] = (dp2[j] + dp[j + 1]) % mod;
                if (j) dp2[j] = (dp2[j] + dp[j - 1]) % mod;
            }
            swap(dp2, dp);
        }
        return dp[0];
    }
};