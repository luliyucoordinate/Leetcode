package findpeakelement

func findPeakElement(nums []int) int {
	if len(nums) == 1 {
		return 0
	} else if len(nums) == 2 {
		if nums[0] > nums[1] {
			return 0
		}
		return 1
	}
	lo, hi, ans, mid := 0, len(nums)-1, 0, 0
	for lo <= hi {
		mid = lo + (hi-lo)/2
		if mid == 0 || nums[mid] > nums[mid-1] {
			ans = mid
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return ans
}
