func balancedStringSplit(s string) int {
    L, res := 0, 0
    for _, v := range s {
        if v == 'L' {
            L++
        } else {
            L--
        }
        if L == 0 {
            res++
        }
    }
    return res
}