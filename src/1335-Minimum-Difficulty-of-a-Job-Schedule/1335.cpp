class Solution 
{
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        
        int dp[n + 1] = {0};
        for (int i = n - 1; i >= 0; i--) dp[i] = max(dp[i + 1], jobDifficulty[i]);
        
        for (int t = 1; t <= d; t++)
        {
            for (int i = 0; i <= n - t; i++)
            {
                int m = 0; dp[i] = 10010;
                for (int j = i; j <= n - t; j++)
                {
                    m = max(m, jobDifficulty[j]);
                    dp[i] = min(dp[i], m + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};