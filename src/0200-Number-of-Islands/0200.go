var res, r, c int
var d []int

func numIslands(grid [][]byte) int {
    if len(grid) == 0 {
        return 0
    }

    res, r, c = 0, len(grid), len(grid[0])
    d = []int{0, 1, 0, -1, 0}
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == '1' {
                grid[i][j] = '0'
                res++
                dfs(grid, i, j)
            }
        }
    }
    return res
}

func dfs(grid [][]byte, x, y int) {
    for i := 0; i < 4; i++ {
        nx, ny := x + d[i], y + d[i + 1]
        if 0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == '1' {
            grid[nx][ny] = '0'
            dfs(grid, nx, ny)
        }
    }
}