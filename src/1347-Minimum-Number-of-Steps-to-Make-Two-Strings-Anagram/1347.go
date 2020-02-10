func minSteps(s string, t string) int {
    cnt := make([]int, 26)
    n, res := len(s), 0
    
    for i := 0; i < n; i++ {
        cnt[s[i] - 'a']++
        cnt[t[i] - 'a']--
    }
    
    for i := 0; i < 26; i++ {
        if cnt[i] > 0 {
            res += cnt[i]
        }
    }
    return res
}