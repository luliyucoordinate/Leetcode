var parent []int

func minCostToSupplyWater(n int, wells []int, pipes [][]int) int {
    for i, v := range wells {
        pipes = append(pipes, []int{0, i+1, v})
    }
    sort.Sort(IntSlice(pipes))
    parent = make([]int, n+1)
    for i := 0; i <= n; i++ {
        parent[i] = i
    }
    
    e, res, k := 0, 0, 0
    for e < n {
        pre := pipes[k]
        k++
        x, y := find(pre[0]), find(pre[1])
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