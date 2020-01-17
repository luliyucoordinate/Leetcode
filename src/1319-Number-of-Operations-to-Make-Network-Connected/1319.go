var parent []int

func makeConnected(n int, connections [][]int) int {
    if len(connections) < n - 1 {
        return -1
    }
    parent = make([]int, n)
    for i := 0; i < n; i++ {
        parent[i] = i
    }
    
    res := n
    for _, it := range connections {
        x, y := find(it[0]), find(it[1])
        if x != y {
            parent[x] = y
            res--
        }
    }
    return res - 1
}

func find(x int) int {
    if x != parent[x] {
        parent[x] = find(parent[x])
    }
    return parent[x]
}