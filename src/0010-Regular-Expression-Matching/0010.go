func isMatch(s string, p string) bool {
    m, n := len(s), len(p)
    mem := make([][]bool, m + 1)
    for i := 0; i <= m; i++ {
        mem[i] = make([]bool, n + 1)
    }
    mem[0][0] = true
    
    for i := 0; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if p[j-1] == '*' {
                if j > 1 {
                    mem[i][j] = mem[i][j-2]
                } 
                if (i > 0 && j > 1 && s[i-1] == p[j-2]) || (j > 1 && p[j-2] == '.') {
                    mem[i][j] = mem[i][j] || i > 0 && mem[i-1][j]
                }
            } else {
                if (i > 0 && s[i-1] == p[j-1]) || p[j-1] == '.' {
                    mem[i][j] = i > 0 && mem[i-1][j-1]
                }
            }
        }
    }
    return mem[m][n]
}