func checkIfCanBreak(s1 string, s2 string) bool {
    d1 := make([]int, 26)
    d2 := make([]int, 26)
    for _, c := range s1 {
        d1[c - 'a']++
    }
    for _, c := range s2 {
        d2[c - 'a']++
    }
    
    return check(d1, d2) || check(d2, d1)
}

func check(d1, d2 []int) bool {
    s := 0
    for i := 0; i < 26; i++ {
        s += d1[i] - d2[i]
        if s < 0 {
            return false
        }
    }
    return true
}