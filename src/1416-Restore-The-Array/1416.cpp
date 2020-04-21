class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1000000007;
        vector<int> dp(n + 1);
        dp[n] = 1;
        
        for (int i = n - 1; ~i; i--) {
            if (s[i] == '0') continue;
            for (long t = 1, cur = 0; i + t <= n; t++) {
                cur = cur * 10 + s[i + t - 1] - '0';
                if (cur > k) break;
                dp[i] = (dp[i] + dp[i + t]) % mod;
            }
        }
        return dp[0];
    }
};