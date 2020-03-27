func hasValidPath(grid [][]int) bool {
    r, c := len(grid), len(grid[0])
    d := []int{0, 1, 0, -1, 0};
    p := [][]int{{1, 0, 1, 0}, 
                {0, 1, 0, 1}, 
                {0, 1, 1, 0},
                {1, 1, 0, 0},
                {0, 0, 1, 1},
                {1, 0, 0, 1}}
    
    q := [][]int{{0, 0}}
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        x, y := pre[0], pre[1]

        if x == r - 1 && y == c - 1 {
            return true
        } 
        
        k := grid[x][y]
        grid[x][y] = 0
        for i := 0; i < 4; i++ {
            nx, ny := x + d[i], y + d[i + 1]
            if 0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] > 0 && p[k - 1][i] == 1 && p[grid[nx][ny] - 1][i ^ 2] == 1 {
                q = append(q, []int{nx, ny})
            }
        }
    }
    return false
}