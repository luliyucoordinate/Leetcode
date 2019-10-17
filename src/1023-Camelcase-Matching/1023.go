func camelMatch(qs []string, pattern string) []bool {
    res := make([]bool, 0)
    for i := 0; i < len(qs); i++ {
        j, p := 0, 0
        for j, p = 0, 0; j < len(qs[i]); j++ {
            if p < len(pattern) && qs[i][j] == pattern[p] {
                p++
            } else if 'A' <= qs[i][j] && qs[i][j] <= 'Z' {
                break
            }
        }
        res = append(res, j == len(qs[i]) && p == len(pattern))
    }
    return res
}