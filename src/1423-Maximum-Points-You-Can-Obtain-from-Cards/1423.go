func maxScore(cardPoints []int, k int) int {
    res, cur, n := 0, 0, len(cardPoints)
    for i := n - k; i < n + k; i++ {
        cur += cardPoints[i % n]
        if i >= n {
            cur -= cardPoints[i - k]
        }
        res = max(res, cur)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}