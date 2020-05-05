func maxDiff(num int) int {
    a := strconv.Itoa(num)
    b := a
    
    for _, c := range a {
        if c != '9' {
            a = strings.Replace(a, string(c), "9", -1)
            break
        }
    }
    
    if b[0] != '1' {
        b = strings.Replace(b, string(b[0]), "1", -1)
    } else {
        for i := 1; i < len(b); i++ {
            c := b[i]
            if c != '0' && c != '1' {
                b = strings.Replace(b, string(c), "0", -1)
                break
            }
        }
    }
    r1, _ := strconv.Atoi(a)
    r2, _ := strconv.Atoi(b)
    return r1 - r2
}