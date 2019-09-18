func kConcatenationMaxSum(arr []int, k int) int {
    mod, cur, res, total := 1000000007, 0, 0, 0
    for _, v := range arr {
        total += v
    }
    
    for i := 0; i < len(arr)*min(k, 2); i++ {
        cur = max(cur, 0) + arr[i%len(arr)]
        res = max(res, cur)
    }
    return max(max(res, 0), ((k - 2)*total + res)%mod)
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