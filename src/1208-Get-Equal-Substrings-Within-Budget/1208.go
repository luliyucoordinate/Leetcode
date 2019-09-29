func equalSubstring(s string, t string, maxCost int) int {
    d := make([]int, 0)
    for i := 0; i < len(s); i++ {
        d = append(d, abs(int(s[i]) - int(t[i])))
    }
    l, r := 0, 0
    for ; r < len(s); r++ {
        maxCost -= d[r]
        if maxCost < 0 {
            maxCost += d[l]
            l++
        }
    }
    return r - l
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}