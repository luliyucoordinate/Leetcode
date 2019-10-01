type pair struct {
    word string
    num int
}

func longestStrChain(words []string) int {
    mem := make([][]pair, 17)
    for i := 0; i <= 16; i++ {
        mem[i] = make([]pair, 0)
    }
    
    for _, w := range words {
        mem[len(w)] = append(mem[len(w)], pair{word:w, num:1})
    }
    
    res := 1
    for i := 2; i <= 16; i++ {
        for j := 0; j < len(mem[i]); j++ {
            for k := 0; k < len(mem[i-1]); k++ {
                if (isPreString(mem[i-1][k].word, mem[i][j].word)) {
                    mem[i][j].num = max(mem[i][j].num, mem[i-1][k].num + 1)
                } 
                res = max(res, mem[i][j].num)
            }
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func isPreString(s1, s2 string) bool {
    p, n := 0, len(s1)
    for i := 0; i < n; i++ {
        if s1[i] != s2[i + p] {
            p++
            if p != 1 {
                return false
            } else {
                i--
            }
        }
    }
    return true
}