class Solution {
    public int numberOfArrays(String s, int k) {
        int n = s.length(), mod = 1000000007;
        int[] dp = new int[n + 1];
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') continue;
            long cur = 0;
            for (int t = 1; i + t <= n; t++) {
                cur = cur * 10 + s.charAt(i + t - 1) - '0';
                if (cur > k) break;
                dp[i] = (dp[i] + dp[i + t]) % mod;
            }
        }
        return dp[0];
    }
}