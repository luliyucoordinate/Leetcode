func minimumSemesters(N int, relations [][]int) int {
    g := make([][]int, N)
    for i := 0; i < N; i++ {
        g[i] = []int{}
    }
    
    degrees := make([]int, N)
    for _, v := range relations {
        x, y := v[0] - 1, v[1] - 1
        g[x] = append(g[x], y)
        degrees[y]++
    }
    
    num, res := 0, 0
    q := []int{}
    for i := 0; i < N; i++ {
        if degrees[i] == 0 {
            q = append(q, i)
            num++
        }
    }
    
    for len(q) > 0 {
        n := len(q)
        for i := 0; i < n; i++ {
            v := q[0]
            q = q[1:]
            for _, w := range g[v] {
                degrees[w]--
                if degrees[w] == 0 {
                    q = append(q, w)
                    num++
                }
            }
        }
        res++
    }
    if num == N {
        return res
    }
    return -1
}