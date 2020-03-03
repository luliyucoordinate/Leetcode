func minCost(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    q := [][]int{{0, 0, 0}}
    d := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
    vis := make([]bool, m * n)
    dist := make([]int, m * n)
    for i := 0; i < m * n; i++ {
        dist[i] = 1000000000
    }
    dist[0] = 0
    
    for len(q) > 0 {
        t := q[0]
        q = q[1:]
        step, x, y := t[0], t[1], t[2]
        if vis[x * n + y] {
            continue
        }
        vis[x * n + y] = true
        
        for i := 1; i <= 4; i++ {
            nx, ny := x + d[i - 1][0], y + d[i - 1][1]
            new_dist := step
            if grid[x][y] != i {
                new_dist++
            }
            
            if nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx * n + ny] > new_dist {
                dist[nx * n + ny] = new_dist
                if grid[x][y] != i {
                    q = append(q, []int{dist[nx * n + ny], nx, ny})
                } else {
                    q = append([][]int{{dist[nx * n + ny], nx, ny}}, q...)
                }
            }
        }
    }
    return dist[m * n - 1]
}