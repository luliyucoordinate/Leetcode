func countTriplets(arr []int) int {
    n, res, prefix, c, t := len(arr), 0, 0, 0, 0
    cnt := make(map[int]int)
    total := make(map[int]int)
    cnt[0] = 1
    
    for i := 0; i < n; i++ {
        prefix ^= arr[i]
        if cur, ok := cnt[prefix]; ok {
            c = cur
        } else {
            c = 0
        }
        if cur, ok := total[prefix]; ok {
            t = cur
        } else {
            t = 0
        }
        res += c * i - t
        cnt[prefix], total[prefix] = c + 1, t + i + 1
    }
    return res
}