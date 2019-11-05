var g map[int][]int
var res int

func treeDiameter(edges [][]int) int {
    res = 0
    g = make(map[int][]int)
    for _, it := range edges {
        g[it[0]] = append(g[it[0]], it[1])
        g[it[1]] = append(g[it[1]], it[0])
    }
    dfs(0, -1)
    return res
}

func dfs(cur, pre int) int {
    d1, d2 := 0, 0
    for _, i := range g[cur] {
        if i != pre {
            d := dfs(i, cur)
            if d > d1 {
                tmp := d1
                d1, d2 = d, tmp
            } else if d > d2 {
                d2 = d
            }
        }
    }
    res = max(res, d1 + d2)
    return d1 + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}