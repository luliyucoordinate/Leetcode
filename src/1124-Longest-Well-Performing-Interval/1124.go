func longestWPI(hours []int) int {
    res, pre_sum := 0, 0
    seen := make(map[int]int)
    for i, v := range hours {
        if v > 8 {
            pre_sum++
        } else {
            pre_sum--
        }
        if _, ok := seen[pre_sum]; !ok {
            seen[pre_sum] = i
        }
        if pre_sum > 0 {
            res = i + 1
        } else if _, ok := seen[pre_sum - 1]; ok {
            res = max(res, i - seen[pre_sum - 1])
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