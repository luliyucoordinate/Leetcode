package searchinrotatedsortedarray

func search(nums []int, target int) int {
	var mid int
	lo, hi := 0, len(nums)-1
	for lo <= hi {
		mid = lo + (hi-lo)/2
		if nums[mid] == target {
			return mid
		} else if nums[lo] <= nums[mid] {
			if nums[mid] < target || target < nums[lo] {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		} else {
			if nums[mid] > target || target > nums[hi] {
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		}
	}
	return -1
}
