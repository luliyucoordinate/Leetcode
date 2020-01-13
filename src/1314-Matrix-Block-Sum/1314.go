func matrixBlockSum(mat [][]int, K int) [][]int {
    r, c := len(mat), len(mat[0])
    pre := make([][]int, r + 1)
    for i := 0; i <= r; i++ {
        pre[i] = make([]int, c + 1)
    }
    
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j]
        }
    }
    
    res := make([][]int, r)
    for i := 0; i < r; i++ {
        res[i] = make([]int, c)
    }
    
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            r1, c1, r2, c2 := max(0, i - K), max(0, j - K), min(r, i + K + 1), min(c, j + K + 1)
            res[i][j] = pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1]
        }
    }
    return res
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