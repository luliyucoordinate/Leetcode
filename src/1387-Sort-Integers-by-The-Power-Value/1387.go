func getKth(lo int, hi int, k int) int {
    n := hi - lo + 1
    res := make([]int, n)
    for i := lo; i <= hi; i++ {
        res[i - lo] = i
    }
    
    sort.Slice(res, func(i, j int) bool {
        p1, p2 := cal(res[i]), cal(res[j])
        if p1 == p2 {
            return res[i] < res[j]
        } 
        return p1 < p2
    })
    return res[k - 1]
}

func cal(x int) int {
    res := 0
    for x != 1 {
        if x % 2 == 1 {
            x = x * 3 + 1
        } else {
            x >>= 1
        }
        res++
    }
    return res
}