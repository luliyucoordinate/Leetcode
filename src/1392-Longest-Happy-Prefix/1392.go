func longestPrefix(s string) string {
    n := len(s)
    i, j := 0, -1
    f := make([]int, n + 1)
    f[0] = -1
    
    for i < n {
        for j != -1 && s[i] != s[j] {
            j = f[j]
        }
        i++
        j++
        f[i] = j
    }
    return s[:f[n]]
}