func minimumMoves(grid [][]int) int {
    n := len(grid)
    dp := make([][][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([][]int, n)
        for j := 0; j < n; j++ {
            dp[i][j] = []int{100000, 100000}
        }
    }
    
    dp[0][0][0] = 0
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if j < n - 1 && grid[i][j] == 0 && grid[i][j + 1] == 0 {
                if j > 0 {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + 1)
                }
                if i > 0 {
                    dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + 1)
                }
            }
            if i < n - 1 && grid[i][j] == 0 && grid[i + 1][j] == 0 {
                if j > 0 {
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + 1)
                }
                if i > 0 { 
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + 1)
                }
            }
            if i < n - 1 && j < n - 1 && grid[i][j+1] == 0 && grid[i+1][j] == 0 && grid[i+1][j+1] == 0 {
                dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1)
                dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1)
            }
        }
    }
    res := dp[n-1][n-2][0]
    if res == 100000 {
        return -1
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}