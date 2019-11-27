func minTimeToVisitAllPoints(p [][]int) int {
    res := 0
    for i := 1; i < len(p); i++ {
        res += max(abs(p[i][0] - p[i-1][0]), abs(p[i][1] - p[i-1][1]))
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}