func numTimesAllBlue(light []int) int {
    res, maxv := 0, 0
    for i := 0; i < len(light); i++ {
        maxv = max(maxv, light[i])
        if maxv == i + 1 {
            res++
        }
    }
    return res
    
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}