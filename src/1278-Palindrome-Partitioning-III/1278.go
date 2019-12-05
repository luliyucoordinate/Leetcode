func palindromePartition(s string, k int) int {
    n := len(s)
    p := make([][]int, n)
    for i := 0; i < n; i++ {
        p[i] = make([]int, n)
    }
    for j := 1; j < n; j++ {
        for i := j - 1; i >= 0; i-- {
            if s[i] != s[j] {
                p[i][j] = 1
            } 
            if i + 1 < j {
                p[i][j] += p[i + 1][j - 1]
            }
        }
    }
    
    f := make([][]int, k + 1)
    for i := 0; i <= k; i++ {
        f[i] = make([]int, n)
        for j := 0; j < n; j++ {
            f[i][j] = 100
        }
    }
    for i := 0; i < n; i++ {
        f[1][i] = p[0][i]
    }
    for i := 2; i <= k; i++ {
        for r := i - 1; r < n; r++ {
            for l := i - 2; l < r; l++ {
                f[i][r] = min(f[i][r], f[i-1][l] + p[l+1][r])
            }
        }
    }
    return f[k][n-1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}