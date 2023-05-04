package sortcolors

func sortColors(nums []int) {
	lo, mid, hi := 0, 0, len(nums)-1
	for mid <= hi {
		if nums[mid] == 2 {
			nums[mid], nums[hi] = nums[hi], nums[mid]
			hi--
		} else if nums[mid] == 0 {
			nums[lo], nums[mid] = nums[mid], nums[lo]
			lo++
			mid++
		} else {
			mid++
		}
	}
}
