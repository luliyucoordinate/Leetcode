func balancedString(s string) int {
    cnt := make(map[byte]int)
    n := len(s)
    res, i, avg := n, 0, n/4
    for _, v := range []byte(s) {
        cnt[v]++
    }
    for j := 0; j < n; j++ {
        cnt[s[j]]--
        for i < n && cnt['Q'] <= avg && cnt['W'] <= avg && cnt['E'] <= avg && cnt['R'] <= avg {
            res = min(res, j - i + 1)
            cnt[s[i]]++
            i++
        }
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}