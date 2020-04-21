func getHappyString(n int, k int) string {
    prem := 1 << (n - 1)
    if prem * 3 < k {
        return ""
    }
    
    k--
    s := []byte{byte(97 + k / prem)}
    for prem > 1 {
        k %= prem
        prem >>= 1
        if k / prem == 0 {
            if s[len(s) - 1] == 'a' {
                s = append(s, 'b')
            } else {
                s = append(s, 'a')
            }
        } else {
            if s[len(s) - 1] != 'c' {
                s = append(s, 'c')
            } else {
                s = append(s, 'b')
            }
        }
    }
    return string(s)
}