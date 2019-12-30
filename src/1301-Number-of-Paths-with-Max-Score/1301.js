var pathsWithMaxScore = function(b) {
    let n = b.length, mod = 1000000007;
    let d = [[0, 1], [1, 0], [1, 1]], dp = [];
    for (let i = 0; i <= n; i++) {
        dp[i] = dp[i] || [];
        for (let j = 0; j <= n; j++) {
            dp[i][j] = new Array(2);
            dp[i][j].fill(0);
        }
    }
    dp[n-1][n-1][1] = 1;
    
    for (let x = n - 1; x >= 0; x--) {
        for (let y = n - 1; y >= 0; y--) {
            if (b[x][y] == 'X' || b[x][y] == 'S') continue;
            for (let it of d) {
                if (dp[x][y][0] < dp[x+it[0]][y+it[1]][0])
                    dp[x][y] = [dp[x+it[0]][y+it[1]][0], 0];
                if (dp[x][y][0] == dp[x+it[0]][y+it[1]][0])
                    dp[x][y][1] = (dp[x][y][1] + dp[x+it[0]][y+it[1]][1]) % mod;
            }
            dp[x][y][0] += x || y ? Number(b[x][y]) : 0;
        }
    }
    return [dp[0][0][1] ? dp[0][0][0] : 0, dp[0][0][1]];
};