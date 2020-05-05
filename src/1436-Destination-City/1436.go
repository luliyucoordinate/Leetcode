func destCity(paths [][]string) string {
    s := make(map[string]int)
    for _, path := range paths {
        s[path[0]] = 1
    }
    for _, path := range paths {
        if _, ok := s[path[1]]; !ok {
            return path[1]
        }
    }
    return ""
}