func removeDuplicates(S string) string {
    res := make([]rune, 0)
    for _, c := range S {
        if (len(res) > 0 && res[len(res)-1] == c) {
            res = res[:len(res)-1]
        } else {
            res = append(res, c)
        }
    }
    return string(res)
}