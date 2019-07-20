func shortestPathBinaryMatrix(grid [][]int) int {
    if len(grid) == 0 {
        return -1
    }
    
    r, c := len(grid), len(grid[0])
    if grid[r-1][c-1] == 1 || grid[0][0] == 1 {
        return -1
    }

    dire := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
    q := [][]int{{0, 0, 1}}
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        if pre[0] == r-1 && pre[1] == c-1 {
            return pre[2]
        }
        for _, v := range dire {
            nx, ny := v[0] + pre[0], v[1] + pre[1]
            if nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0{
                grid[nx][ny] = 1
                q = append(q, []int{nx, ny, pre[2] + 1})
            }
        }
    }
    return -1
}