const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX
func movesToMakeZigzag(nums []int) int {
    res := make([]int, 2)
    nums = append([]int{INT_MAX}, nums...)
    nums = append(nums, INT_MAX)
    for i := 1; i < len(nums) - 1; i++ {
        res[i % 2] += max(0, nums[i] - min(nums[i-1], nums[i+1]) + 1)
    }
    return min(res[0], res[1])
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