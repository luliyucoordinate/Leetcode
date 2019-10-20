func f(str string) int {
    cnt, minChar := 0, '~'
    for _, c := range str {
        if c < minChar {
            minChar, cnt = c, 1
        } else if c == minChar {
            cnt++
        }
    }
    return cnt
}

func numSmallerByFrequency(queries []string, words []string) []int {
    res := make([]int, len(queries))
    w := make([]int, len(words))
    for i, word := range words {
        w[i] = f(word)
    }
    sort.Ints(w)
    
    for i, v := range queries {
        cnt, l, r := f(v), 0, len(w) - 1
        for l < r {
            mid := (l + r) >> 1
            if cnt < w[mid] {
                r = mid
            } else {
                l = mid + 1
            }
        }
        
        if cnt >= w[l] {
            l++
        }
        res[i] = len(w) - l
    }
    return res
}