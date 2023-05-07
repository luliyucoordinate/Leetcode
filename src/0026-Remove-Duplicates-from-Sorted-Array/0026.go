package removeduplicatesfromsortedarray

func removeDuplicates(nums []int) int {
	for i := 0; i < len(nums); {
		if i > 0 && nums[i] == nums[i-1] {
			nums = append(nums[:i], nums[i+1:]...)
		} else {
			i++
		}
	}
	return len(nums)
}
