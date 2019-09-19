var g [][]int
var low []int
var res [][]int

func criticalConnections(n int, connections [][]int) [][]int {
    g = make([][]int, n)
    low = make([]int, n)
    res = make([][]int, 0)
    for _, e := range connections {
        g[e[0]] = append(g[e[0]], e[1])
        g[e[1]] = append(g[e[1]], e[0])
    }
    dfs(1, 0, -1)
    return res
}

func dfs(cur, v, p int) {
    dfn := cur
    low[v] = cur
    for _, i := range g[v] {
        if i != p {
            if low[i] == 0 {
                cur++
                dfs(cur, i, v)
                if low[i] > dfn {
                    res = append(res, []int{i, v})
                }
            }
            low[v] = min(low[v], low[i])
        }
    }
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}