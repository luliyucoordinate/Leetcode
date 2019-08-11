func minSwaps(data []int) int {
    n := len(data)
    pre := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        pre[i] = pre[i - 1] + data[i - 1]
    }
    
    res, m := pre[n], pre[n]
    for i := m; i < n; i++ {
        res = min(res, m - (pre[i] - pre[i - m]))
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}