func rankTeams(votes []string) string {
    n := len(votes[0])
    cnt := make([][]int, 26)
    for i := 0; i < 26; i++ {
        cnt[i] = make([]int, n + 1)
        cnt[i][n] = i
    }
    
    for _, vote := range votes {
        for i := 0; i < n; i++ {
            cnt[vote[i] - 'A'][i]--
        }
    }
    
    res := []byte(votes[0])
    sort.Slice(res, func(a, b int) bool {
        for i := 0; i <= n; i++ {
            if cnt[res[a] - 'A'][i] == cnt[res[b] - 'A'][i] {
                continue
            }
            return cnt[res[a] - 'A'][i] < cnt[res[b] - 'A'][i]
        }
        return true
    })
    return string(res)
}