func constrainedSubsetSum(nums []int, k int) int {
    q := []int{}
    res, n := -10000, len(nums)

    for i := 0; i < n; i++ {
        if len(q) > 0 && q[0] > 0 {
            nums[i] += q[0]
        }
        for len(q) > 0 && nums[i] > q[len(q) - 1] {
            q = q[:len(q) - 1]
        }
        q = append(q, nums[i])
        
        if i >= k && len(q) > 0 && q[0] == nums[i - k] {
            q = q[1:]
        }
        res = max(res, nums[i])
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}