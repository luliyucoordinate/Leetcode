func removeSubfolders(folder []string) []string {
    sort.Strings(folder)
    res := make([]string, 0)
    l, parent := 2, ""
    for _, f := range folder {
        if f[:min(len(f), l)] != parent {
            l, parent = len(f) + 1, f + "/"
            res = append(res, f)
        }
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}