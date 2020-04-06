func canConstruct(s string, k int) bool {
    odds, n := 0, len(s)
    cnt := make([]int, 26)
    for i := 0; i < n; i++ {
        cnt[s[i] - 'a'] ^= 1
        if cnt[s[i] - 'a'] > 0 {
            odds++
        } else {
            odds--
        }
    }
    return odds <= k && k <= n
}