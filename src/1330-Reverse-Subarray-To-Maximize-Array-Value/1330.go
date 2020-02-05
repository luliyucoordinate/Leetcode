func maxValueAfterReverse(nums []int) int {
    n, total, res, Hi, Lj := len(nums),0, 0, 100010, -100010
    for i := 0; i < n - 1; i++ {
        a, b := nums[i], nums[i+1]
        total += abs(a - b)
        Hi, Lj = min(Hi, max(a, b)), max(Lj, min(a, b))
        res = max(res, max(abs(nums[0] - b) - abs(a - b), max(abs(a - nums[n-1]) - abs(a - b), (Lj - Hi) * 2)))
    }
    return total + res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}