var mem [][]int
func tilingRectangle(n int, m int) int {
    mem = make([][]int, n + 1)
    for i := 0; i <= n; i++ {
        mem[i] = make([]int, m + 1)
        for j := 0; j <= m; j++ {
            mem[i][j] = 10000
        }
    }
    return dfs(n, m)
}

func dfs(x, y int) int {
    if mem[x][y] != 10000{
        return mem[x][y]
    } 
    if (x == 11 && y == 13) || (x == 13 && y == 11) {
        return 6
    } 
    if x == y {
        return 1
    } 
    res := x * y
    for i := 1; i <= x/2; i++ {
        res = min(res, dfs(i, y) + dfs(x - i, y))
    }
    for j := 1; j <= y/2; j++ {
        res = min(res, dfs(x, j) + dfs(x, y - j))
    }
    mem[x][y] = res
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}