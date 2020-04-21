func numberOfArrays(s string, k int) int {
    n, mod := len(s), 1000000007
    dp := make([]int, n + 1)
    dp[n] = 1
    
    for i := n - 1; i >= 0; i-- {
        if s[i] == '0' {
            continue
        }
        var cur int64 = 0
        for t := 1; i + t <= n; t++ {
            cur = cur * 10 + int64(s[i + t - 1] - '0')
            if cur > int64(k) {
                break
            }
            dp[i] = (dp[i] + dp[i + t]) % mod
        }
    }
    return dp[0]
}