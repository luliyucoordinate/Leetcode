func maxSatisfaction(s []int) int {
    sort.Ints(s)
    res, total, n := 0, 0, len(s)
    
    for i := n - 1; i >= 0 && s[i] > -total; i-- {
        total += s[i]
        res += total
    }
    return res
}