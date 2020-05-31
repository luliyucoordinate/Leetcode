var g map[int][]int

func minTime(n int, edges [][]int, hasApple []bool) int {
    g = make(map[int][]int)
    for _, edge := range edges {
        i, j := edge[0], edge[1]
        g[i] = append(g[i], j)
        g[j] = append(g[j], i)
    }
    
    vis := make([]bool, n)
    vis[0] = true
    return dfs(0, hasApple, vis)
}

func dfs(x int, hasApple, vis []bool) int {
    res := 0
    for _, i := range g[x] {
        if vis[i] {
            continue
        }
        vis[i] = true
        
        cur := dfs(i, hasApple, vis)
        if cur > 0 {
            res += cur + 2
        } else if hasApple[i] {
            res += 2
        }
    }
    return res
}