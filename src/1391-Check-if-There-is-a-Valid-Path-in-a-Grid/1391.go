func hasValidPath(grid [][]int) bool {
    r, c := len(grid), len(grid[0])
    d := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    p := [][]int{{2, -1, 0, -1}, 
                {-1, 3, -1, 1}, 
                {-1, 2, 1, -1},
                {1, 0, -1, -1},
                {-1, -1, 3, 2},
                {3, -1, -1, 0}}
    
    q := [][]int{{0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}}
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        x, y, di := pre[0], pre[1], pre[2]
        
        if p[grid[x][y] - 1][di] == -1 {
            continue
        } 
        if x == r - 1 && y == c - 1 {
            return true
        } 
        
        dx, dy := d[p[grid[x][y] - 1][di]][0], d[p[grid[x][y] - 1][di]][1];
        nx, ny := x + dx, y + dy;
        if 0 <= nx && nx < r && 0 <= ny && ny < c {
            q = append(q, []int{nx, ny, (p[grid[x][y] - 1][di] + 2) % 4})
        }
    }
    return false
}