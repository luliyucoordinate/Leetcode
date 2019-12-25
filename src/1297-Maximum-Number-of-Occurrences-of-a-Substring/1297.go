func maxFreq(s string, maxLetters int, minSize int, maxSize int) int {
    cnt := make(map[string]int)
    for i := 0; i <= len(s) - minSize; i++ {
        cnt[s[i:i + minSize]]++
    }
    
    cntStr := make(map[int][]string)
    for k, v := range cnt {
        cntStr[v] = append(cntStr[v], k)
    }
    
    keys := make([]int, 0)
    for k := range cntStr {
        keys = append(keys, k)
    }
    sort.Ints(keys)
    
    for i := len(keys) - 1; i >= 0; i-- {
        for _, str := range cntStr[keys[i]] {
            sCnt := make(map[rune]int)
            nq := 0
            for _, c := range str {
                if sCnt[c] == 0 {
                    nq++
                    if nq > maxLetters {
                        break
                    }
                    sCnt[c]++
                }
            }
            if nq <= maxLetters {
                return keys[i]
            }
        }
    }
    return 0
}