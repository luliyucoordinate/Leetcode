var r, c, mod int
var dp [][][]int
var g [][]int


func ways(pizza []string, k int) int {
    r, c, mod = len(pizza), len(pizza[0]), 1000000007
    dp = make([][][]int, r)
    g = make([][]int, r + 1)
    for i := 0; i < r; i++ {
        dp[i] = make([][]int, c)
        for j := 0; j < c; j++ {
            dp[i][j] = make([]int, k)
        }
    }
    for i := 0; i <= r; i++ {
        g[i] = make([]int, c + 1)
    }
    for i := r - 1; i >= 0; i-- {
        for j := c - 1; j >= 0; j-- {
            g[i][j] = g[i][j + 1] + g[i + 1][j] - g[i + 1][j + 1]
            if pizza[i][j] == 'A' {
                g[i][j] += 1
            }
        }
    }
    return dfs(0, 0, k - 1)
}

func dfs(i, j, k int) int {
    if dp[i][j][k] != 0 {
        return dp[i][j][k]
    }
    if g[i][j] == 0 {
        return 0
    }
    if k == 0 {
        return 1
    }
    
    res := 0
    for x := i + 1; x < r; x++ {
        if g[i][j] - g[x][j] > 0 {
            res = (res + dfs(x, j, k - 1)) % mod
        }
    }
    for y := j + 1; y < c; y++ {
        if g[i][j] - g[i][y] > 0 {
            res = (res + dfs(i, y, k - 1)) % mod
        }
    }
    dp[i][j][k] = res
    return res
}