func myAtoi(str string) int {
    str = strings.TrimSpace(str)
    if len(str) == 0 {
        return 0
    }
    var res int64 = 0
    neg, ix := 1, 0
    if str[0] == '+' || str[0] == '-' {
        if str[0] == '+' {
            neg = 1
        }else {
            neg = -1
        }
        ix++
    }
    
    for _, val := range str[ix:] {
        if val < '0' || val > '9' {
            break
        }
        res = res * 10 + int64(val - '0')
        if res > math.MaxInt32 {
            if neg == -1 {
                return math.MinInt32
            } else {
                return math.MaxInt32
            }
        }
    }
    return int(res) * neg
}