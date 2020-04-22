func minNumberOfFrogs(cr string) int {
    res, frogs := 0, 0
    st := make([]int, 5)
    for _, i := range []byte(cr) {
        if i == 'c' {
            st[0]++
            frogs++
        } else if i == 'r' {
            st[1]++
        } else if i == 'o' {
            st[2]++
        } else if i == 'a' {
            st[3]++
        } else {
            st[4]++
            frogs--
        }
        res = max(res, frogs)
        if st[0] < st[1] || st[1] < st[2] || st[2] < st[3] || st[3] < st[4] {
            return -1
        }
    }
    
    if st[0] == st[1] && st[1] == st[2] && st[2] == st[3] && st[3] == st[4] {
        return res
    }
    return -1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}