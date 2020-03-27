func surfaceArea(grid [][]int) int {
    res, r, c := 0, len(grid), len(grid[0])
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] > 0 {
                res += grid[i][j] * 4 + 2
            }
            if i > 0 {
                res -= min(grid[i - 1][j], grid[i][j]) * 2
            }
            if j > 0 {
                res -= min(grid[i][j - 1], grid[i][j]) * 2
            }
        }
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}