func longestCommonPrefix(strs []string) string {
    res := ""
    if len(strs) < 1 {
        return res
    }
    
    for i := 0; i < len(strs[0]); i++ {
        c := strs[0][i]
        for j := 1; j < len(strs); j++ {
            if i + 1 > len(strs[j]) || c != strs[j][i] {
                return res
            }
        }
        res += string(c)
    }
    return res
}