var g [][]int

func frogPosition(n int, edges [][]int, t int, target int) float64 {
    if n == 1 {
        return 1.0
    }
    
    g = make([][]int, n + 1)
    for i := 0; i <= n; i++ {
        g[i] = []int{}
    }
    for _, it := range edges {
        g[it[0]] = append(g[it[0]], it[1])
        g[it[1]] = append(g[it[1]], it[0])
    }
    
    return dfs(-1, 1, t, target)
}

func dfs(fa, cur, t, target int) float64 {
    if cur != 1 && len(g[cur]) == 1 || t == 0 {
        if cur == target {
            return 1
        }
        return 0
    }
    
    var res float64 = 0
    for _, i := range g[cur] {
        if i != fa {
            res = math.Max(res, dfs(cur, i, t - 1, target))
        }
    }
    if cur != 1 {
        return res / float64(len(g[cur]) - 1)
    }
    return res / float64(len(g[cur]))
}