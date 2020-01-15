func repeatedSubstringPattern(s string) bool {
    t := s + s
    return strings.Contains(t[1:len(t)-1], s)
}