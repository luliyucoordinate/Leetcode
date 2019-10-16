func canFinish(n int, pre [][]int) bool {
    g := make(map[int][]int)
    d := make([]int, n)
    q := make([]int, 0)
    vis := make([]int, n)
    for _, v := range pre {
        g[v[1]] = append(g[v[1]], v[0])
        d[v[0]]++
    }
    
    for i := 0; i < n; i++ {
        if d[i] == 0 {
            q = append(q, i)
            vis[i] = 1
        }
    }
    
    for len(q) > 0 {
        cur := q[0]
        q = q[1:]
        n--
        for _, i := range g[cur] {
            d[i]--
            if vis[i] == 0 && d[i] == 0 {
                q = append(q, i)
                vis[i] = 1
            }
        }
    }
    return n == 0
}