func shiftGrid(grid [][]int, k int) [][]int {
    n, m := len(grid), len(grid[0])
    res := make([][]int, n)
    for i := 0; i < n; i++ {
        res[i] = make([]int, m)
    }
    
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            t := j + k
            res[(i + t / m)%n][t % m] = grid[i][j]
        }
    }
    return res
}