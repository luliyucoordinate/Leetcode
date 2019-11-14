func uniqueLetterString(S string) int {
    res, f, mod := 0, 0, 1000000007
    m := make([]int, 26)
    n := make([]int, 26)
    for i, v := range S {
        t := int(v) - 65
        f = f + 1 + i - 2 * m[t] + n[t]
        res = (res + f) % mod
        n[t], m[t] = m[t], i + 1
    }
    return res
}