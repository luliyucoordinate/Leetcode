func numWays(steps int, arrLen int) int {
    m, n, mod := steps, min(steps/2 + 1, arrLen), 1000000007
    dp := make([]int, n + 1)
    dp[0] = 1
    
    for i := 1; i <= m; i++ {
        dp2 := make([]int, n + 1)
        for j := 0; j < n; j++ {
            dp2[j] = (dp2[j] + dp[j]) % mod
            dp2[j] = (dp2[j] + dp[j + 1]) % mod
            if j > 0 {
                dp2[j] = (dp2[j] + dp[j - 1]) % mod
            }
        }
        dp = dp2
    }
    return dp[0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}