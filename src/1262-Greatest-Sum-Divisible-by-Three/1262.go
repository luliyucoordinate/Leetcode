func maxSumDivThree(nums []int) int {
    res := make([]int, 3)
    for _, a := range nums {
        tmp := make([]int, 3)
        copy(tmp, res)
        for _, i := range tmp {
            res[(i + a)%3] = max(res[(i + a)%3], i + a)
        }
    }
    return res[0]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}