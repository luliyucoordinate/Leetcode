func removeVowels(S string) string {
    reg := regexp.MustCompile(`(a|e|i|o|u)`)
    return reg.ReplaceAllString(S, "")
}