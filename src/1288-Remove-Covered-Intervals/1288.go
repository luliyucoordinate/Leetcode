func removeCoveredIntervals(A [][]int) int {
    sort.Slice(A, func(i, j int) bool {
        if A[i][0] == A[j][0] {
            return A[i][1] > A[j][1]
        }
        return A[i][0] < A[j][0]
    })
    
    res, r := 0, 0
    for _, v := range A {
        if v[1] > r {
            res++
        }
        r = max(r, v[1])
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}