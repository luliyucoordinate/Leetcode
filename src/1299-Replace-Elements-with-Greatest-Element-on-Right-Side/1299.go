func replaceElements(arr []int) []int {
    max_right := -1
    for i := len(arr) - 1; i >= 0; i-- {
        max_right, arr[i] = max(arr[i], max_right), max_right
    }
    return arr
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}