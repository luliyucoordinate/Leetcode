func breakPalindrome(palindrome string) string {
    p := []byte(palindrome)
    for i := 0; i < len(p)/2; i++ {
        if p[i] != 'a' {
            p[i] = 'a'
            return string(p)
        }
    }
    if len(p) < 2 {
        return ""
    }
    p[len(p) - 1] = 'b'
    return string(p)
}