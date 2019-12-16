func minFallingPathSum(A [][]int) int {
    r, c := len(A), len(A[0])
    for i := r - 1; i > 0; i-- {
        m1, m2 := []int{20000, 0}, []int{20000, 0}
        for k := 0; k < c; k++ {
            if A[i][k] < m1[0] {
                copy(m2, m1)
                m1[0], m1[1] = A[i][k], k
            } else if A[i][k] < m2[0] {
                m2[0], m2[1] = A[i][k], k
            }
        }
        
        for j := 0; j < c; j++ {
            if j != m1[1] {
                A[i-1][j] += m1[0]
            } else {
                A[i-1][j] += m2[0]
            }
        }
    }
    
    res := 20000
    for i := 0; i < c; i++ {
        res = min(res, A[0][i])
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}