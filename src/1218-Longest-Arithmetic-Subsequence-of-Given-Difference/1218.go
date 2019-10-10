func longestSubsequence(arr []int, dif int) int {
    mem := make(map[int]int)
    res := 1
    for _, i := range arr {
        if v, ok := mem[i - dif]; ok {
            mem[i] = v + 1
        } else {
            mem[i] = 1
        }
        res = max(res, mem[i])
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}