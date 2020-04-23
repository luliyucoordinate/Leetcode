func numOfArrays(n int, m int, k int) int {
    mod := 1000000007
    dp := make([][][]int, n + 1)
    for i := 0; i <= n; i++ {
        dp[i] = make([][]int, k + 1)
        for j := 0; j <= k; j++ {
            dp[i][j] = make([]int, m + 1)
        }
    }
    
    for c := 0; c <= m; c++ {
        dp[1][1][c] = c
    }
    for a := 2; a <= n; a++ {
        for b := 1; b <= k; b++ {
            for c := b; c <= m; c++ {
                dp[a][b][c] = (dp[a][b][c - 1] + dp[a - 1][b - 1][c - 1] + 
                               (dp[a - 1][b][c] - dp[a - 1][b][c - 1] + mod) * c) % mod
            }
        }
    }
    return dp[n][k][m]
}