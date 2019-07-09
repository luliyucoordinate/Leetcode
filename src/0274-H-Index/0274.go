func hIndex(citations []int) int {
    n := len(citations)
    cnt := make([]int, n + 1)
    for _, c := range citations {
        cnt[min(c, n)]++
    }
    
    i := n
    for total := cnt[n]; i > total; total += cnt[i] {
        i--
    }
    return i
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}