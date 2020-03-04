func orangesRotting(grid [][]int) int {
    r, c := len(grid), len(grid[0])
    cnt, step := 0, 0
    d := []int{0, 1, 0, -1, 0}
    q := [][]int{}
    
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == 1 {
                cnt++
            } else if grid[i][j] == 2 {
                q = append(q, []int{i, j})
            }
        }
    }
    
    for len(q) > 0 {
        if cnt == 0 {
            return step
        }
        
        for k := len(q); k > 0; k-- {
            t := q[0]
            q = q[1:]
            x, y := t[0], t[1]
            
            for i := 0; i < 4; i++ {
                nx, ny := x + d[i], y + d[i + 1]
                if nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1 {
                    cnt--
                    q = append(q, []int{nx, ny})
                    grid[nx][ny] = 2
                }
            }
        }
        step++;
    }
    
    if cnt == 0 {
        return step
    }
    return -1
}