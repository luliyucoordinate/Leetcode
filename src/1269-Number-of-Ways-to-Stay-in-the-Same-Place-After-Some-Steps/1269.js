var numWays = function(steps, arrLen) {
    let m = steps, n = Math.min(Math.floor(steps/2) + 1, arrLen), mod = 1000000007;
    let dp = new Array(n + 1); dp.fill(0);
    dp[0] = 1;
        
    for (let i = 1; i <= m; i++) {
        let dp2 = new Array(n + 1); dp2.fill(0);
        for (let j = 0; j < n; j++) {
            dp2[j] = (dp2[j] + dp[j]) % mod;
            dp2[j] = (dp2[j] + dp[j + 1]) % mod;
            if (j > 0) dp2[j] = (dp2[j] + dp[j - 1]) % mod;
        }
        dp = dp2;
    }
    return dp[0];
};