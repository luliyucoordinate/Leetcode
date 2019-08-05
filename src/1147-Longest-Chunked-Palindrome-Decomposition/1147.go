func longestDecomposition(text string) int {
    var n = len(text);
    for i := 1; i <= n/2; i++ {
        if text[:i] == text[n-i:] {
            return 2 + longestDecomposition(text[i:n-i])
        }
    }
    if n == 0 {
        return 0
    }
    return 1
}