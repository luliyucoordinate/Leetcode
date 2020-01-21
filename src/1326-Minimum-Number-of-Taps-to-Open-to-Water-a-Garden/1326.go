func minTaps(n int, ranges []int) int {
    data := make([]int, n + 1)
    for i := 0; i < len(ranges); i++ {
        l, r := max(0, i - ranges[i]), min(n, i + ranges[i])
        data[l] = max(data[l], r - l)
    }
    
    pre, cur, step := -1, 0, 0
    for i := 0; i <= n; i++ {
        if cur < i {
            return -1
        }
        if cur >= n {
            return step
        }
        if pre < i && i <= cur {
            step++
            pre = cur
        }
        cur = max(cur, i + data[i])
    }
    return step
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}