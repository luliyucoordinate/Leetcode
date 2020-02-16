func countNegatives(grid [][]int) int {
    r, c := len(grid), len(grid[0])
    res, m, n := 0, r - 1, 0
    
    for m >= 0 && n < c {
        if grid[m][n] < 0 {
            res += c - n
            m--
        } else {
            n++
        }
    }
    return res
}