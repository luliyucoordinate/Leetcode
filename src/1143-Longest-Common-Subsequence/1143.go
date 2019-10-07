func longestCommonSubsequence(text1 string, text2 string) int {
    m, n := len(text1), len(text2)
    l := make([][]int, m + 1)
    for i := 0; i <= m; i++ {
        l[i] = make([]int, n + 1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if text1[i-1] == text2[j-1] {
                l[i][j] = l[i-1][j-1] + 1
            } else {
                l[i][j] = max(l[i][j-1], l[i-1][j])
            }
        }
    }
    return l[m][n]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}