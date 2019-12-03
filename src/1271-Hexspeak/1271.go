func toHexspeak(num string) string {
    data, _ := strconv.ParseInt(num, 10, 64)
    dataToHex := fmt.Sprintf("%x",data)
    res := make([]rune, 0)
    for _, i := range dataToHex {
        if i > '1' && i <= '9' {
            return "ERROR"
        }
        if i == '0' {
            res = append(res, 'O')
        } else if i == '1' {
            res = append(res, 'I')
        } else {
            res = append(res, unicode.ToUpper(rune(i)))
        }
    }
    return string(res)
}