func gcdOfStrings(s1 string, s2 string) string {
    if s1 + s2 == s2 + s1 {
        return s1[:gcd(len(s1), len(s2))]
    }
    return ""
}

func gcd(a, b int) int {
    if b > 0 {
        return gcd(b, a % b)
    }
    return a
}