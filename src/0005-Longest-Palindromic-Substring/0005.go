func longestPalindrome(s string) string {
    if len(s) == 0 {
        return ""
    }
    sn := make([]byte, len(s)*2 + 2)
    sn[0], sn[1] = '$', '#'

    l := 2
    for _, val := range []byte(s) {
        sn[l] = val
        l++
        sn[l] = '#'
        l++
    }
    
    p := make([]int, l)
    mid, r := 0, 0
    mi, mr := 0, 0
    for i := 1; i < l; i++ {
        if r > mid {
            if p[2*mid - i] < r - i {
                p[i] = p[2*mid - i]
            } else {
                p[i] = r - i
            }
        } else {
            p[i] = 1
        }

        for i + p[i] < l && sn[i - p[i]] == sn[i + p[i]] {
            p[i]++
        }
        if i + p[i] > r {
            r, mid = p[i] + i, i
        }
        if p[i] - 1 > mi {
            mi = p[i] - 1
            mr = (i - p[i]) / 2
        }
    }
    return s[mr:mr+mi]
}