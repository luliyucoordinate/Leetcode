func minRemoveToMakeValid(s string) string {
    st := make([]int, 0)
    for i, c := range s {
        if c == '(' {
            st = append(st, i)
        }else if c == ')' {
            if len(st) > 0 && s[st[len(st) - 1]] == '(' {
                st = st[:len(st) - 1]
            }else { 
                st = append(st, i)
            }
        }
    }
    res, pre := "", 0
    for _, i := range st {
        res += s[pre:i]
        pre = i + 1
    }
    res += s[pre:]
    return res
}

