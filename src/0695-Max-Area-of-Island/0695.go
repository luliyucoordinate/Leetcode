var r, c int
var d []int

func maxAreaOfIsland(grid [][]int) int {
    r, c = len(grid), len(grid[0])
    d = []int{0, 1, 0, -1, 0}
    res := 0

    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == 1 {
                grid[i][j] = 0
                res = max(res, dfs(grid, i, j))
            }
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func dfs(grid [][]int, x, y int) int {
    res := 1
    for i := 0; i < 4; i++ {
        nx, ny := x + d[i], y + d[i + 1]
        if 0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == 1 {
            grid[nx][ny] = 0
            res += dfs(grid, nx, ny)
        }
    }
    return res
}