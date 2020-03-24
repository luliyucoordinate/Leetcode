func createTargetArray(nums []int, index []int) []int {
    res := make([]int, len(nums))
	for i, v := range index {
		copy(res[v + 1:i + 1], res[v:i])
		res[v] = nums[i]
	}
	return res
}