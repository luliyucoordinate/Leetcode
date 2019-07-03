func romanToInt(s string) int {
    s_dict := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    res, pre := 0, 0
    for _, ch := range []byte(s) {
        cur := s_dict[ch]
        if pre < cur {
            res += cur - 2 * pre
        } else {
            res += cur
        }
        pre = cur
    }
    return res
}