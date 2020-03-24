var n, k int

func maxSizeSlices(slices []int) int {
    n = len(slices)
    k = n / 3
    return max(cal(slices, 0, n - 1), cal(slices, 1, n))
}

func cal(nums []int, l, r int) int {
    dp := make([][]int, 2)
    for i := 0; i < 2; i++ {
        dp[i] = make([]int, k + 1)
    }
    
    for i := l; i < r; i++ {
        for j := k; j > 0; j-- {
            dp[0][j] = dp[1][j]
            dp[1][j] = max(dp[1][j], dp[0][j - 1] + nums[i])
        }
    }
    return dp[1][k]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}