func reverseParentheses(s string) string {
    st := make([]int, 0)
    pair := make(map[int]int)
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            st = append(st, i)
        }
        if s[i] == ')' {
            j := st[len(st)-1]
            st = st[:len(st)-1]
            pair[i], pair[j] = j, i
        }
    }
    
    res := make([]byte, 0)
    i, d := 0, 1
    for i < len(s) {
        if s[i] == ')' || s[i] == '(' {
            i, d = pair[i], -d
        } else {
            res = append(res, s[i])
        }
        i += d
    }
    return string(res)
}