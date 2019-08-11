func canConvert(str1 string, str2 string) bool {
    s2 := make(map[rune]int)
    for _, v := range str2 {
        s2[v]++
    }
    if len(s2) == 26 {
        return str1 == str2
    }
    
    d := make(map[byte]byte) 
    for i := 0; i < len(str1); i++ {
        if _, ok := d[str1[i]]; ok {
            if d[str1[i]] != str2[i] {
                return false
            }
        } else {
            d[str1[i]] = str2[i]
        }
    }
    return true
}