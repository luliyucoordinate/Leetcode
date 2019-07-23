func mctFromLeafValues(arr []int) int {
    res := 0
    const INT_MAX = int(^uint(0) >> 1)
    s := []int{INT_MAX}
    for _, a := range arr {
        for s[len(s) - 1] <= a {
            cur := s[len(s) - 1]
            s = s[:len(s) - 1]
            res += min(s[len(s) - 1], a) * cur
        }
        s = append(s, a)
    }
    for len(s) > 2 {
        cur := s[len(s) - 1]
        s = s[:len(s) - 1]
        res += s[len(s) - 1] * cur
    }
    return res
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}