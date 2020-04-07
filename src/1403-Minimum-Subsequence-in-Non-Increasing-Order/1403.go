func minSubsequence(nums []int) []int {
    sort.Ints(nums)
    res := make([]int, 0)
    cur, t := 0, 0
    
    for _, i := range nums {
        t += i
    }
    t >>= 1
    
    for i := len(nums) - 1; i >= 0; i-- {
        cur += nums[i]
        res = append(res, nums[i])
        if cur > t {
            return res
        }
    }
    return res
}