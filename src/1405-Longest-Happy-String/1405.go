func longestDiverseString(a int, b int, c int) string {
    return dfs(a, b, c, "a", "b", "c")
}

func dfs(A, B, C int, a, b, c string) string {
    if A < B {
        return dfs(B, A, C, b, a, c)
    } 
    
    if B < C {
        return dfs(A, C, B, a, c, b)
    } 
    
    if B == 0 {
        return strings.Repeat(a, min(2, A))
    } 
    
    na, nb := min(2, A), 0
    if A - na + 1 >= B {
        nb = 1
    } 
    return strings.Repeat(a, na) + strings.Repeat(b, nb) + dfs(A - na, B - nb, C, a, b, c)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}