func sortString(s string) string {
    cnt := make([]int, 26)
    for _, c := range []byte(s) {
        cnt[c - 'a']++
    }
    
    var res bytes.Buffer
    n := len(s)    
    
    for n > 0 {
        for i := 0; i < 26; i++ {
            if cnt[i] > 0 {
                res.WriteString(string(i + 97))
                cnt[i]--
                n--
            }
        }
        
        for i := 25; i >= 0; i-- {
            if cnt[i] > 0 {
                res.WriteString(string(i + 97))
                cnt[i]--
                n--
            }
        }
    }
    return res.String()
}