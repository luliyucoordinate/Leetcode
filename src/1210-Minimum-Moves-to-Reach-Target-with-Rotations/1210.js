var minimumMoves = function(grid) {
    let n = grid.length, dp = [];
    for (let i = 0; i < n; i++) {
        dp[i] = [];
        for (let j = 0; j < n; j++) {
            dp[i][j] = [100000, 100000];
        }
    }
    dp[0][0][0] = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (j < n - 1 && grid[i][j] == 0 && grid[i][j + 1] == 0) {
                if (j) dp[i][j][0] = Math.min(dp[i][j][0], dp[i][j-1][0] + 1);
                if (i) dp[i][j][0] = Math.min(dp[i][j][0], dp[i-1][j][0] + 1);
            }
            if (i < n - 1 && grid[i][j] == 0 && grid[i + 1][j] == 0) {
                if (j) dp[i][j][1] = Math.min(dp[i][j][1], dp[i][j-1][1] + 1);
                if (i) dp[i][j][1] = Math.min(dp[i][j][1], dp[i-1][j][1] + 1);
            }
            if (i < n - 1 && j < n - 1 && grid[i][j+1] == 0 && grid[i+1][j] == 0 && grid[i+1][j+1] == 0) {
                dp[i][j][0] = Math.min(dp[i][j][0], dp[i][j][1] + 1);
                dp[i][j][1] = Math.min(dp[i][j][1], dp[i][j][0] + 1);
            }
        }
    }
    return dp[n-1][n-2][0] == 100000 ? -1 : dp[n-1][n-2][0];
};