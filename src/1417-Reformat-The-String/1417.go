func reformat(s string) string {
    digits := []rune{}
    chars := []rune{}
    for _, c := range s {
        if c >= '0' && c <= '9' {
            digits = append(digits, c)
        } else {
            chars = append(chars, c)
        }
    }
    
    if abs(len(digits) - len(chars)) > 1 {
        return ""
    }
    
    var res strings.Builder
    flag := false
    if len(digits) >= len(chars) {
        flag = true
    }
    
    for i := 0; i < len(s); i++ {
        if flag {
            res.WriteRune(digits[len(digits) - 1])
            digits = digits[:len(digits) - 1]
        } else {
            res.WriteRune(chars[len(chars) - 1])
            chars = chars[:len(chars) - 1]
        }
        flag = !flag
    }
    return res.String()
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}