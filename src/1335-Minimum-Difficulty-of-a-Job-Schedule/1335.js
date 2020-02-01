var minDifficulty = function(jobDifficulty, d) {
    let n = jobDifficulty.length;
    if (n < d) return -1;

    let dp = new Array(n + 1);
    dp.fill(0);
    for (let i = n - 1; i >= 0; i--) {
        dp[i] = Math.max(dp[i + 1], jobDifficulty[i]);
    }

    for (let t = 1; t <= d; t++) {
        for (let i = 0; i <= n - t; i++) {
            let m = 0; dp[i] = 10010;
            for (let j = i; j <= n - t; j++) {
                m = Math.max(m, jobDifficulty[j]);
                dp[i] = Math.min(dp[i], m + dp[j + 1]);
            }
        }
    }
    return dp[0];
};