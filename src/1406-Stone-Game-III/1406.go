func stoneGameIII(stoneValue []int) string {
    n, sum := len(stoneValue), 0
    dp := make([]int, 3)
    
    for i := n - 1; i >= 0; i-- {
        sum += stoneValue[i]
        minv := min(dp[(i + 1) % 3], dp[(i + 2) % 3])
        minv = min(minv, dp[(i + 3) % 3])
        dp[i % 3] = sum - minv
    }
    
    if dp[0] * 2 == sum {
        return "Tie"
    } else if dp[0] * 2 > sum {
        return "Alice"
    }
    return "Bob"
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}