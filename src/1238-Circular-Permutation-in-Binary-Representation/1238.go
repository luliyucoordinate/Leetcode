func circularPermutation(n int, start int) []int {
    res, e := make([]int, 0), int(1 << uint(n))
    for i := 0; i < e; i++ {
        res = append(res, start^i^(i >> 1))
    }
    return res
}