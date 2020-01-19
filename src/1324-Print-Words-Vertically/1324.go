func printVertically(s string) []string {
    strs := strings.Split(s, " ")
    max_len := 0
    for _, st := range strs {
        max_len = max(max_len, len(st))
    }
    
    res := []string{}
    for j := 0; j < max_len; j++ {
        t, t_len := []byte{}, 0
        for _, st := range strs {
            if len(st) > j {
                t = append(t, st[j])
                t_len = len(t)
            } else {
                t = append(t, ' ')
            }
        }
        res = append(res, string(t[:t_len]))
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}