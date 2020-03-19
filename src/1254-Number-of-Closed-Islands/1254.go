var d []int
var r, c, res int

func closedIsland(g [][]int) int {
    r, c, res = len(g), len(g[0]), 2
    d = []int{0, 1, 0, -1, 0}
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if g[i][j] == 0 {
                g[i][j] = res
                dfs(g, i, j)
                res++
            }
        }
    }
    
    color := make(map[int]int)
    color[0], color[1] = 1, 1
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if i == 0 || i == r - 1 {
                color[g[i][j]] = 1
            } else if j == 0 || j == c - 1 {
                color[g[i][j]] = 1
            } 
        }
    }
    return res - len(color)
}

func dfs(g [][]int, x, y int) {
    for i := 0; i < 4; i++ {
        nx, ny := x + d[i], y + d[i + 1]
        if 0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] == 0 {
            g[nx][ny] = res
            dfs(g, nx, ny)
        }
    }
}