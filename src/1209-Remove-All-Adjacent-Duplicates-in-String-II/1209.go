type pair struct {
    char rune
    num int
}

func removeDuplicates(s string, k int) string {
    st := make([]pair, 0)
    st = append(st, pair{char:'#', num:0})
    for _, c := range s {
        if c == st[len(st)-1].char {
            st[len(st) - 1].num++
            if st[len(st) - 1].num == k {
                st = st[:len(st)-1]
            }
        } else {
            st = append(st, pair{char:c, num:1})
        }
    }
    
    res := ""
    for _, it := range st {
        res += strings.Repeat(string(it.char), it.num)
    }
    return res
}