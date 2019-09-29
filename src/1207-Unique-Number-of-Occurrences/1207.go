func uniqueOccurrences(arr []int) bool {
    m := make(map[int]int)
    for _, i := range arr {
        m[i]++
    }
    s := make(map[int]int)
    for _, v := range m {
        s[v] = 1
    }
    return len(s) == len(m)
}