var n int
var cnt []int

func maxScoreWords(words []string, letters []byte, score []int) int {
    cnt = make([]int, 26)
    n = len(words)
    for _, c := range letters {
        cnt[int(c) - 97]++
    }
    return dfs(0, words, score)
}

func dfs(i int, words []string, score []int) int {
    if i == n {
        return 0
    }    
    
    res, tmp, val := max(0, dfs(i + 1, words, score)), 0, 1
    for _, c := range words[i] {
        t := int(c) - 97
        cnt[t]--
        tmp += score[t]
        if cnt[t] < 0 {
            val = 0
        }
    }
    
    if val == 1 {
        res = max(res, dfs(i + 1, words, score) + tmp)
    }
    for _, c := range words[i] {
        cnt[int(c) - 97]++
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}