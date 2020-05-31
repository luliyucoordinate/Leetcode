var ways = function(pizza, K) {
    let r = pizza.length, c = pizza[0].length, mod = 1000000007;
    let dp = Array(r), g = Array(r + 1);
    for (let i = 0; i < r; i++) {
        dp[i] = Array(c);
        for (let j = 0; j < c; j++) dp[i][j] = Array(K).fill(0);
    }
    for (let i = 0; i <= r; i++) g[i] = Array(c + 1).fill(0);
    
    for (let i = r - 1; i >= 0; i--) {
        for (let j = c - 1; j >= 0; j--) {
            g[i][j] = g[i][j + 1] + g[i + 1][j] - g[i + 1][j + 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
        }
    }
    
    let dfs = function(i, j, k) {
        if (dp[i][j][k] != 0) return dp[i][j][k];
        if (g[i][j] == 0) return 0;
        if (k == 0) return 1;
        
        let res = 0;
        for (let x = i + 1; x < r; x++) {
            if (g[i][j] - g[x][j] > 0) res = (res + dfs(x, j, k - 1)) % mod;
        }
        for (let y = j + 1; y < c; y++) {
            if (g[i][j] - g[i][y] > 0) res = (res + dfs(i, y, k - 1)) % mod;
        }
        dp[i][j][k] = res;
        return res;
    }
    return dfs(0, 0, K - 1);
};