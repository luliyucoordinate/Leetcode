func oddEvenJumps(A []int) int {
    n := len(A)
    d := make([]int, n)
    for i := 0; i < n; i++ {
        d[i] = i
    }
    sort.SliceStable(d, func(i, j int) bool {
        return A[d[i]] < A[d[j]]
    })
    n1 := st(d)
    sort.SliceStable(d, func(i, j int) bool {
        return A[d[i]] > A[d[j]]
    })
    n2 := st(d)
    
    h := make([]int, n)
    l := make([]int, n)
    h[n - 1], l[n - 1] = 1, 1
    for i := n - 2; i >= 0; i-- {
        h[i] = l[n1[i]]
        l[i] = h[n2[i]]
    }
    res := 0
    for i := 0; i < n; i++ {
        if h[i] > 0 {
            res++
        }
    }
    return res
}

func st(data []int) []int {
    n := len(data)
    s := make([]int, 0)
    res := make([]int, n)
    for _, i := range data {
        for len(s) > 0 && s[len(s) - 1] < i {
            res[s[len(s) - 1]] = i
            s = s[:len(s) - 1]
        }
        s = append(s, i)
    }
    return res
}