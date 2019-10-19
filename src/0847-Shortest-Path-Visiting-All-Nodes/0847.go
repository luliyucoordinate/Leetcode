func shortestPathLength(graph [][]int) int {
    n := uint(len(graph))
    t, res := uint((1 << n) - 1), 0
    q := make([][]uint, n)
    mem := make([][]uint, n)
    for i := uint(0); i < n; i++ {
        mem[i] = make([]uint, 1 << n);
        q[i] = []uint{i, 1 << i}
    }
    for true {
        nq := len(q)
        for i := 0; i < nq; i++ {
            pre := q[0]
            q = q[1:]
            if pre[1] == t {
                return res
            }
            for _, j := range graph[pre[0]] {
                k, new_stat := uint(j), pre[1] | 1 << uint(j)
                if mem[k][new_stat] == 0 {
                    q = append(q, []uint{k, new_stat})
                    mem[k][new_stat] = 1
                }
            }
        }
        res++
    }
    return 0
}