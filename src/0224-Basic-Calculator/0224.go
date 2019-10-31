func calculate(s string) int {
    st := make([]int, 0)
    op, l, r := 1, 0, 0
    for _, c := range s {
        if c >= '0' && c <= '9' {
            r = r * 10 + (int(c) - 48)
        } else if c == '+' || c == '-' {
            l += op * r
            r = 0
            if c == '+' {
                op = 1
            } else {
                op = -1
            }
        } else if c == '(' {
            st = append(st, l)
            st = append(st, op)
            op, l = 1, 0
        } else if c == ')' {
            l += op * r
            r = 0
            l = st[len(st) - 1] * l + st[len(st) - 2]
            st = st[:len(st) - 2]
        }
    }
    return l + op * r
}