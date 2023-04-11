package findminimuminrotatedsortedarray

func findMin(nums []int) int {
	var mid int
	lo, hi := 0, len(nums)-1
	for lo < hi {
		mid = lo + (hi-lo)/2
		if nums[mid] > nums[hi] {
			lo = mid + 1
		} else {
			hi = mid
		}
	}
	return nums[lo]
}
