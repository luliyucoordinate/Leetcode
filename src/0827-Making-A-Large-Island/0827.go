var dire [][]int

func largestIsland(g [][]int) int {
    dire = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
    data := []int{0, 0}
    r, c, res := len(g), len(g[0]), 0
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if g[i][j] == 1 {
                data = append(data, dfs(i, j, len(data), g))
            }
        }
    }
    
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if g[i][j] != 0 {
                continue
            }
            s := make(map[int]int)
            tmp := 0
            for _, d := range dire {
                color := check(i + d[0], j + d[1], g)
                if _, ok := s[color]; ok {
                    continue
                }
                s[color] = 1
                tmp += data[color]
            }
            res = max(res, tmp + 1)
        }
    }
    
    if res == 0 {
        return r * c
    }
    return res
}

func check(i, j int, g [][]int) int {
    if i < 0 || j < 0 || i >= len(g) || j >= len(g[0]) {
        return 0
    }
    return g[i][j]
}

func dfs(i, j, color int, g [][]int) int {
    if check(i, j, g) != 1 {
        return 0
    }
    g[i][j] = color
    res := 1
    for _, d := range dire {
        res += dfs(i + d[0], j + d[1], color, g)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}