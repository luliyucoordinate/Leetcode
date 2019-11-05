func numberOfSubarrays(nums []int, k int) int {
    return atMost(nums, k) - atMost(nums, k - 1)
}

func atMost(nums []int, k int) int {
    res, i := 0, 0
    for j := 0; j < len(nums); j++ {
        k -= nums[j] % 2
        for k < 0 {
            k += nums[i] % 2
            i++
        }
        res += j - i + 1
    }
    return res
}