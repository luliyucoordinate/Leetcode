func maxRepOpt1(s string) int {
    res, l, n, mf, mc := 0, 0, len(s), 0, s[0]
    d, cnt := make(map[byte]int), make(map[byte]int)
    for _, v := range []byte(s) {
        cnt[v]++
    }
    for r := 0; r < n; r++ {
        d[s[r]]++
        if mf < d[s[r]] {
            mf = d[s[r]]
            mc = s[r]
        }

        for r - l + 1 - mf > 1 {
            d[s[l]]--
            l++
        }
        res = max(res, r - l + 1)
    }
    return min(res, cnt[mc])
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