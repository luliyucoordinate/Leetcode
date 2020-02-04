func minSetSize(arr []int) int {
    n, total, res := len(arr)/2, 0, 0
    freq := make(map[int]int)
    cnt := make(map[int]int)
    for _, v := range arr {
        freq[v]++
    }
    for _, v := range freq {
        cnt[v]++
    }
    
    cnt_keys := []int{}
    for k := range cnt {
        cnt_keys = append(cnt_keys, k)
    }
    sort.Slice(cnt_keys, func(i, j int) bool {
        return cnt_keys[i] > cnt_keys[j]
    })
    
    for _, i := range cnt_keys {
        dif := n - total
        x := min(cnt[i], (dif + i - 1)/i)
        res += x
        total += x * i
        if total >= n {
            return res
        }
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}