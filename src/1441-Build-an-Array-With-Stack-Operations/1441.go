func buildArray(target []int, n int) []string {
    res := []string{}
    k := 1
    
    for i := 0; i < len(target); i, k = i + 1, k + 1 {
        if target[i] == k {
            res = append(res, "Push")
        } else {
            i--
            res = append(res, "Push")
            res = append(res, "Pop")
        }
    }
    return res
}