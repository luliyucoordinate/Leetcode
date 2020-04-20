func minStartValue(nums []int) int {
    pref, min_pref := 0, 0
    for _, i := range nums {
        pref += i
        min_pref = min(min_pref, i)
    }
    return 1 - min_pref
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}