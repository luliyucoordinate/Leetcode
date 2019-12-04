func countSquares(A [][]int) int {
    res := 0
    for i := 0; i < len(A); i++ {
        for j := 0; j < len(A[0]); j++ {
            if i > 0 && j > 0 && A[i][j] > 0 {
                A[i][j] = min(A[i - 1][j], min(A[i][j - 1], A[i - 1][j - 1])) + 1
            }  
            res += A[i][j];
        }
    }
    return res;
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}