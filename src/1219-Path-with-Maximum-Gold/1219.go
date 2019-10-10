var d,g [][]int
var m, n int

func getMaximumGold(grid [][]int) int {
    d = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    m, n, g = len(grid), len(grid[0]), grid
    res := 0
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] > 0 {
                res = max(res, g[i][j] + dfs(i, j))
            }
        }
    }
    return res
}

func dfs(x, y int) int {
    res, src := 0, g[x][y]
    g[x][y] = 0
    for _, i := range d {
        nx, ny := x + i[0], y + i[1]
        if nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] > 0 {
            res = max(res, g[nx][ny] + dfs(nx, ny))
        }
    }
    g[x][y] = src
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}