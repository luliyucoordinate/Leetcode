func minDifficulty(jobDifficulty []int, d int) int {
    n := len(jobDifficulty)
    if n < d {
        return -1
    }
    
    dp := make([]int, n + 1)
    for i := n - 1; i >= 0; i-- {
        dp[i] = max(dp[i + 1], jobDifficulty[i])
    }
    
    for t := 1; t <= d; t++ {
        for i := 0; i <= n - t; i++ {
            m := 0
            dp[i] = 10010
            for j := i; j <= n - t; j++ {
                m = max(m, jobDifficulty[j])
                dp[i] = min(dp[i], m + dp[j + 1])
            }
        }
    }
    return dp[0]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}