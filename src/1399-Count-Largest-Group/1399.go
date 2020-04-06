func countLargestGroup(n int) int {
    cnt := make([]int, 37)
    mx, res := 0, 0
    
    for i := 1; i <= n; i++ {
        c, x := 0, i
        for x > 0 {
            c += x % 10
            x /= 10
        }
        cnt[c]++
        mx = max(mx, cnt[c])
    }
    
    for _, v := range cnt {
        if v == mx {
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