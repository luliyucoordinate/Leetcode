func minCostToMoveChips(chips []int) int {
    res := make([]int, 2)
    for _, v := range chips {
        res[v%2]++
    }
    return min(res[0], res[1])
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}