func numKLenSubstrNoRepeats(S string, K int) int {
    res, low := 0, -1
    usedChar := make(map[byte]int)
    for i, v := range []byte(S) {
        if uv, ok := usedChar[v]; ok && uv >= low {
            low = uv
        }
        if i - low >= K {
            res++
        }
        usedChar[v] = i
    }
    return res
}