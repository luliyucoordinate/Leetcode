func shortestAlternatingPaths(n int, red_edges [][]int, blue_edges [][]int) []int {
    g := [2]map[int][]int{}
    g[0], g[1] = make(map[int][]int), make(map[int][]int)
    for _, v := range red_edges {
        g[0][v[0]] = append(g[0][v[0]], v[1])
    }
    for _, v := range blue_edges {
        g[1][v[0]] = append(g[1][v[0]], v[1])
    }

    q := [][]int{{0, 0, 0}, {0, 1, 0}}
    vis := make(map[int]int)
    vis[0], vis[1] = 1, 1
    
    res := make([]int, n)
    for i := 1; i < n; i++ {
        res[i] = 800
    }
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        if res[pre[0]] > pre[2] {
            res[pre[0]] = pre[2]
        }

        nc := 1 - pre[1]
        for _, v := range g[nc][pre[0]] {
            k := v * 401 + nc
            if vis[k] != 1 {
                q = append(q, []int{v, nc, pre[2] + 1})
                vis[k] = 1
            }
        } 
    }
    for i, v := range res {
        if v == 800 {
            res[i] = -1
        }
    }
    return res
}