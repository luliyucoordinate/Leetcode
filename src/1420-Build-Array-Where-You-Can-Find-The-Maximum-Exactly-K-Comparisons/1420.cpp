class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int mod = 1000000007;
        long long dp[n + 1][k + 1][m + 1];
        memset(dp, 0, sizeof dp);
        
        for (int c = 0; c <= m; c++) dp[1][1][c] = c;
        for (int a = 2; a <= n; a++) {
            for (int b = 1; b <= k; b++) {
                for (int c = b; c <= m; c++) {
                    dp[a][b][c] = (dp[a][b][c - 1] + dp[a - 1][b - 1][c - 1] +
                                  (dp[a - 1][b][c] - dp[a - 1][b][c - 1] + mod) * c) % mod;
                }
            }
        }
        return dp[n][k][m];
    }
};