func maxSideLength(A [][]int, t int) int {
    r, c := len(A), len(A[0])
    pre := make([][]int, r + 1)
    for i := 0; i <= r; i++ {
        pre[i] = make([]int, c + 1)
    }
    
    for i := 1; i <= r; i++ {
        for j := 1; j <= c; j++ {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + A[i-1][j-1]
        }
    }
    
    res, l := 0, 0
    for i := 0; i <= r; i++ {
        for j := 0; j <= c; j++ {
            for i + l <= r && j + l <= c && pre[i+l][j+l]-pre[i+l][j]-pre[i][j+l]+pre[i][j] <= t {
                res, l = l, l + 1
            }
        }
    }
    return res
}