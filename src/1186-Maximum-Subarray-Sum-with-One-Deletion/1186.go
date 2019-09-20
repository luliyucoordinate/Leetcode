func maximumSum(arr []int) int {
    deleted, notDeleted, res := 0, 0, -10000
    for i, a := range arr {
        deleted = max(deleted + a, a)
        if i > 0 {
            deleted = max(deleted, notDeleted)
        }
        notDeleted = max(notDeleted + a, a)
        res = max(res, deleted)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}