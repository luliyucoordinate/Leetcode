func probabilityOfHeads(prob []float64, target int) float64 {
    dp := make([]float64, len(prob) + 1)
    dp[0] = 1.0
    for i := 0; i < len(prob); i++ {
        for k := target; k >= 0; k-- {
            if k > 0 {
                dp[k] = dp[k - 1] * prob[i] + dp[k] * (1 - prob[i])
            } else {
                dp[k] = dp[k] * (1 - prob[i])
            }
        }
    }
    return dp[target]
}