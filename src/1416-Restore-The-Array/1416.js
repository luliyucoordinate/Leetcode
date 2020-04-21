var numberOfArrays = function(s, k) {
    let n = s.length, mod = 1000000007;
    let dp = Array(n + 1).fill(0);
    dp[n] = 1;

    for (let i = n - 1; i >= 0; i--) {
        if (s.charAt(i) == '0') continue;
        for (let cur = 0, t = 1; i + t <= n; t++) {
            cur = cur * 10 + s.charCodeAt(i + t - 1) - 48;
            if (cur > k) break;
            dp[i] = (dp[i] + dp[i + t]) % mod;
        }
    }
    return dp[0];
};