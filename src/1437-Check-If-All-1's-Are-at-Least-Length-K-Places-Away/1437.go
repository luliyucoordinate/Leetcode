func kLengthApart(nums []int, k int) bool {
    for pre, i := -k - 1, 0; i < len(nums); i++ {
        if nums[i] == 1 {
            if i - pre <= k {
                return false
            }
            pre = i
        }
    }
    return true
}