class Solution 
{
public:
    int dieSimulator(int n, vector<int>& rollMax) 
    {
        int dp[6][16], tmp[6], mod = 1e9 + 7;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < 6; i++) tmp[i] = dp[i][1] = 1;
        
        int res = 6, ts;
        for (int i = 1; i < n; i++)
        {
            ts = 0;
            for (int j = 0; j < 6; j++)
            {
                dp[j][0] = ((res - tmp[j])%mod + mod)%mod;
                tmp[j] = 0;
                for (int k = rollMax[j]; k > 0; k--)
                {
                    tmp[j] = (tmp[j] + (dp[j][k] = dp[j][k-1])) % mod;
                }
                ts = (ts + tmp[j])%mod;
            }
            res = ts;
        }
        return res;
    }
};