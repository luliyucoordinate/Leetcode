func maxScore(s string) int {
    zeros, ones, res, n := 0, 0, -1000, len(s)
    for i := 0; i < n; i++ {
        if s[i] == '0' {
            zeros++
        } else {
            ones++
        }
        if i != n - 1{
            res = max(res, zeros - ones)
        }
    }
    return res + ones
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}