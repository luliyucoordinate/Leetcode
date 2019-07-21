func longestArithSeqLength(A []int) int {
    n, res, cM := len(A), 0, 10000
    idx := make([]int, cM + 1)
    for i, _ := range idx {
        idx[i] = -1
    }
    f := make([][]int, n)
    for i := 0; i < n; i++ {
        f[i] = make([]int, n)
    }
    
    for i := 0; i < n - 1; i++ {
        for j := i + 1; j < n; j++ {
            pre := 2 * A[i] - A[j]
            if pre >= 0 && pre <= cM && idx[pre] != -1 {
                f[i][j] = f[idx[pre]][i] + 1
            } else {
                f[i][j] = 2
            }
            if res < f[i][j] {
                res = f[i][j]
            }
        }
        idx[A[i]] = i
    }
    return res
}