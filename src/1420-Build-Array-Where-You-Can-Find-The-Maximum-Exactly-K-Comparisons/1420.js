var numOfArrays = function(n, m, k) {
    let mod = 1000000007;
    let dp = Array(n + 1);
    for (let i = 0; i <= n; i++) {
        dp[i] = Array(k + 1);
        for (let j = 0; j <= k; j++) {
            dp[i][j] = Array(m + 1).fill(0);
        }
    }
    
    for (let c = 0; c <= m; c++) dp[1][1][c] = c;
    for (let a = 2; a <= n; a++) {
        for (let b = 1; b <= k; b++) {
            for (let c = b; c <= m; c++) {
                dp[a][b][c] = (dp[a][b][c - 1] + dp[a - 1][b - 1][c - 1] +
                              (dp[a - 1][b][c] - dp[a - 1][b][c - 1] + mod) * c) % mod;
            }
        }
    }
    return dp[n][k][m];
};