var dieSimulator = function(n, rollMax) {
    let dp = new Array(6);
    for (let i = 0; i < 6; i++) {
        dp[i] = new Array(16);
        dp[i].fill(0);
    }
    let tmp = new Array(6), mod = 1e9 + 7;
    for (let i = 0; i < 6; i++) {
        tmp[i] = dp[i][1] = 1;
    }
    
    let res = 6, ts = 0;
    for (let i = 1; i < n; i++) {
        ts = 0;
        for (let j = 0; j < 6; j++) {
            dp[j][0] = ((res - tmp[j])%mod + mod) % mod;
            tmp[j] = 0;
            for (let k = rollMax[j]; k > 0; k--) {
                tmp[j] = (tmp[j] + (dp[j][k] = dp[j][k-1]))%mod;
            }
            ts = (ts + tmp[j]) % mod;
        }
        res = ts;
    }
    return res;
};