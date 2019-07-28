var parent []int
func minimumCost(N int, connections [][]int) int {
    if len(connections) < N - 1 {
        return -1
    }
    sort.Sort(IntSlice(connections))
    parent = make([]int, N)
    for i := 0; i < N; i++ {
        parent[i] = i
    }
    
    e, res, k := 0, 0, 0
    for e < N - 1 {
        pre := connections[k]
        k++
        x, y := find(pre[0] - 1), find(pre[1] - 1)
        if x != y {
            parent[x] = y
            e++
            res += pre[2]
        }
    }
    return res
}

type IntSlice [][]int

func(s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(a, b int) {
    s[a], s[b] = s[b], s[a]
}

func (s IntSlice) Less(a, b int) bool {
    return s[a][2] < s[b][2]
}

func find(x int) int {
    if parent[x] != x {
        parent[x] = find(parent[x])
    }
    return parent[x]
}