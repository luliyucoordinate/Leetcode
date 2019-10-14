func dieSimulator(n int, rollMax []int) int {
    var dp [6][16]int
    var tmp [6]int
    mod := 1000000007
    for i := 0; i < 6; i++ {
        tmp[i], dp[i][1] = 1, 1
    }
    
    res, ts := 6, 0
    for i := 1; i < n; i++ {
        ts = 0
        for j := 0; j < 6; j++ {
            dp[j][0] = ((res - tmp[j])%mod + mod) % mod
            tmp[j] = 0
            for k := rollMax[j]; k > 0; k-- {
                dp[j][k] = dp[j][k-1]
                tmp[j] = (tmp[j] + dp[j][k]) % mod
            }
            ts = (ts + tmp[j]) % mod
        }
        res = ts
    }
    return res
}