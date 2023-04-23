package searchinsertposition

func searchInsert(nums []int, target int) int {
	lo, hi, mid := 0, len(nums)-1, 0
	for lo <= hi {
		mid = lo + (hi-lo)/2
		if target <= nums[mid] {
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	return lo
}
