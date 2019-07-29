func largest1BorderedSquare(grid [][]int) int {
    r, c := len(grid), len(grid[0])
    h, v := make([][]int, r), make([][]int, r)
    for i := 0; i < r; i++ {
        h[i], v[i] = make([]int, c), make([]int, c)
    }
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] > 0 {
                if i == 0 {
                    v[i][j] = 1
                } else {
                    v[i][j] = v[i - 1][j] + 1
                }
                if j == 0 {
                    h[i][j] = 1
                } else {
                    h[i][j] = h[i][j - 1] + 1
                }
            }
        }
    }
    
    res := 0
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            s := min(h[i][j], v[i][j])
            for s > res {
                if v[i][j - s + 1] >= s && h[i - s + 1][j] >= s {
                    res = s
                    break
                }
                s--
            }
        }
    }
    return res * res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}