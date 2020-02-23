func numberOfSubstrings(s string) int {
    cnt, res, l, n := []int{0, 0, 0}, 0, 0, len(s)
    
    for r := 0; r < n; r++ {
        cnt[s[r] - 'a']++
        for cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
            res += n - r
            cnt[s[l] - 'a']--
            l++
        }
    }
    return res
}