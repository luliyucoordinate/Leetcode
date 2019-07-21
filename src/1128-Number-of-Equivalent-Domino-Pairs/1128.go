func numEquivDominoPairs(dominoes [][]int) int {
    cnt := make([]int, 100)
    res := 0
    for _, v := range dominoes {
        k := min(v[0], v[1])*10 + max(v[0], v[1])
        res += cnt[k]
        cnt[k]++
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}