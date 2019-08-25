func calculateTime(keyboard string, word string) int {
    d := make(map[rune]int)
    for i, c := range keyboard {
        d[c] = i
    }
    
    res, pre := 0, 0
    for _, c := range word {
        if d[c] > pre {
            res += d[c] - pre
        } else {
            res += pre - d[c]
        }
        pre = d[c]
    }
    return res
}