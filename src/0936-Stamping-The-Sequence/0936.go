func movesToStamp(stamp string, target string) []int {
    s_len, t_len, t := len(stamp), len(target), []byte(target)
    var check func(k int) bool
    var compareArray func(a, b []byte) bool
    check = func(k int) bool {
        ret := false
        for i := 0; i < s_len; i++ {
            if t[k + i] != '?' {
                if t[k + i] != stamp[i] {
                    return false
                }
                ret = true
            }
        }
        return ret
    }
    
    compareArray = func(a, b []byte) bool {
        for i := 0; i < t_len; i++ {
            if a[i] != b[i] {
                return false
            }
        }
        return true
    }
    
    done := make([]byte, t_len)
    for i := 0; i < t_len; i++ {
        done[i] = '?'
    }
    res := make([]int, 0)
    for !compareArray(done, t) {
        move := false
        for i := 0; i < t_len - s_len + 1; i++ {
            if check(i) {
                move = true;
                res = append(res, i)
                for j := i; j < i + s_len; j++ {
                    t[j] = '?'
                }
            }
        }
        if !move {
            return []int{}
        }
    }
    return reverse(res)
}

func reverse(s []int) []int {
	for i, j := 0, len(s) - 1; i < j; i, j = i + 1, j - 1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}