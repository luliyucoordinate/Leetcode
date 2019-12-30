func pathsWithMaxScore(b []string) []int {
    n, mod := len(b), 1000000007
    d := [][]int{{1, 0}, {0, 1}, {1, 1}}
    dp := make([][][2]int, n + 1)
    for i := 0; i <= n; i++ {
        dp[i] = make([][2]int, n + 1)
    }
    dp[n-1][n-1][1] = 1
    
    for x := n - 1; x >= 0; x-- {
        for y := n - 1; y >= 0; y-- {
            if b[x][y] == 'X' || b[x][y] == 'S' {
                continue
            }
            for _, it := range d {
                if dp[x][y][0] < dp[x+it[0]][y+it[1]][0] {
                    dp[x][y][0] = dp[x+it[0]][y+it[1]][0]
                    dp[x][y][1] = 0
                }
                if dp[x][y][0] == dp[x+it[0]][y+it[1]][0] {
                    dp[x][y][1] = (dp[x][y][1] + dp[x+it[0]][y+it[1]][1]) % mod
                }
            }
            if x > 0 || y > 0 {
                dp[x][y][0] += int(b[x][y]) - 48
            }
        }
    }
    
    if dp[0][0][1] > 0 {
        return []int{dp[0][0][0], dp[0][0][1]}
    }
    return []int{0, 0}
}