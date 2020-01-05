func freqAlphabets(s string) string {
    res := []byte{}
    for i := 0; i < len(s); i++ {
        if i + 2 < len(s) && s[i + 2] == '#' {
            res = append(res, 'j' + (s[i] - '1') * 10 + (s[i+1] - '0'))
            i += 2
        } else {
            res = append(res, 'a' + (s[i] - '1'))
        }
    }
    return string(res)
}