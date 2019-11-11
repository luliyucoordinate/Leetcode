var dire [][]int

func closedIsland(g [][]int) int {
    r, c, res := len(g), len(g[0]), 2
    dire = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if g[i][j] == 0 {
                dfs(i, j, res, g)
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

func check(i, j int, g [][]int) int {
    if i < 0 || j < 0 || i >= len(g) || j >= len(g[0]) {
        return 0
    }
    return 1
}

func dfs(i, j, color int, g [][]int) {
    if check(i, j, g) == 0 || g[i][j] != 0 {
        return 
    }
    g[i][j] = color
    for _, d := range dire {
        dfs(i + d[0], j + d[1], color, g)
    }
}