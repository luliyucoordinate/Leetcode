func characterReplacement(s string, k int) int {
    res, l, n, mf := 0, 0, len(s), 0
    d := make(map[byte]int)
    for r := 0; r < n; r++ {
        d[s[r]]++
        mf = max(mf, d[s[r]])
        for r - l + 1 - mf > k{
            d[s[l]]--
            l++
        }
        res = max(res, r - l + 1)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}