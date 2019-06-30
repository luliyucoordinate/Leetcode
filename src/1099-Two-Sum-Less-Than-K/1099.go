func twoSumLessThanK(A []int, K int) int {
    res, n := -1, len(A)
    sort.Ints(A)
    l, r := 0, n - 1
    
    for l < r {
        t := A[l] + A[r]
        if t >= K {
            r--
        } else {
            if res < t {
                res = t
            }
            l++
        }
    }
    return res
}