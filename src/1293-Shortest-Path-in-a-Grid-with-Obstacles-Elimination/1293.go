func shortestPath(g [][]int, k int) int {
    r, c := len(g), len(g[0])
    if k >= r + c - 3 {
        return r + c - 2
    }
    
    mem := make([][]int, r)
    for i := 0; i < r; i++ {
        mem[i] = make([]int, c)
        for j := 0; j < c; j++ {
            mem[i][j] = 10000
        }
    }
    
    q := [][]int{{0, 0, 0}}
    mem[0][0] = 0
    d, step := []int{0, 1, 0, -1, 0}, 0
    
    for len(q) != 0 {
        for n := len(q); n > 0; n-- {
            pre := q[0]
            q = q[1:]
            if pre[2] > k {
                continue
            }
            
            if pre[0] == r - 1 && pre[1] == c - 1 {
                return step
            }
            
            for i := 0; i < 4; i++ {
                nx, ny := pre[0] + d[i], pre[1] + d[i + 1]
                if nx >= 0 && nx < r && ny >= 0 && ny < c {
                    nPre := pre[2]
                    if g[nx][ny] == 1 {
                        nPre++
                    }
                    if nPre < mem[nx][ny] {
                        q = append(q, []int{nx, ny, nPre})
                        mem[nx][ny] = nPre
                    }
                }
            }
        }
        step++
    }
    return -1
}