func sumZero(n int) []int {
    res := []int{}
    for i := 1 - n; i < n; i += 2 {
        res = append(res, i)
    }
    return res
}