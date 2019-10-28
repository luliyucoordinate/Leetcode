var res int
func maxLength(arr []string) int {
    res = 0
    dfs(arr, 0, "")
    return res
}

func isUnique(s string) bool {
    tmp := make([]int, 26)
    for _, a := range s {
        tmp[a - 'a']++
    }
    for i := 0; i < 26; i++ {
        if tmp[i] > 1 {
            return false
        }
    }
    return true
}

func dfs(arr []string, index int, path string) {
    uq := isUnique(path)
    if uq {
        res = max(res, len(path))
    }
    if index == len(arr) || !uq {
        return
    }
    for i := index; i < len(arr); i++ {
        dfs(arr, i + 1, path + arr[i])
    }
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}