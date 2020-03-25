class Solution {
    public int numWays(int steps, int arrLen) {
        int m = steps, n = Math.min(steps/2 + 1, arrLen), mod = 1000000007;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            int[] dp2 = new int[n + 1];
            for (int j = 0; j < n; j++) {
                dp2[j] = (dp2[j] + dp[j]) % mod;
                dp2[j] = (dp2[j] + dp[j + 1]) % mod;
                if (j > 0) dp2[j] = (dp2[j] + dp[j - 1]) % mod;
            }
            dp = dp2;
        }
        return dp[0];
    }
}