var N int

func processQueries(queries []int, m int) []int {
    n := len(queries)
    N = m + n + 1
    pos := make([]int, m + 1)
    tree := make([]int, n + m + 1)
    
    for i := 1; i <= m; i++ {
        pos[i] = n + i
        update(tree, i + n, 1)
    }
    
    res := []int{}
    for _, i := range queries {
        res = append(res, prefixSum(tree, pos[i] - 1))
        update(tree, pos[i], -1)
        update(tree, n, 1)
        pos[i] = n
        n--
    }
    return res
}

func update(tr []int, x, v int) {
    for i := x; i < N; i += i & -i {
        tr[i] += v
    }
}

func prefixSum(tr []int, x int) int {
    res := 0
    for i := x; i > 0; i -= i & -i {
        res += tr[i]
    }
    return res
}
