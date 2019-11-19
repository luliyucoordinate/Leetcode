func encode(num int) string {
    res := ""
    num++
    for num > 0 {
        res = strconv.Itoa(num & 1) + res
        num >>= 1
    }
    return res[1:]
}