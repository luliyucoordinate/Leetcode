func numSteps(s string) int {
    res, add, n := 0, 0, len(s)
    
    for i := n - 1; i > 0; i-- {
        res++
        if int(s[i] - '0') + add == 1 {
            add = 1
            res++
        }
    }
    return res + add
}