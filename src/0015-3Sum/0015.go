package sum

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	ans := make([][]int, 0)
	if len(nums) < 3 {
		return ans
	}
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		lo, hi := i+1, len(nums)-1
		for lo < hi {
			val := nums[i] + nums[lo] + nums[hi]
			if val > 0 {
				hi--
			} else if val < 0 {
				lo++
			} else {
				temp := []int{nums[i], nums[lo], nums[hi]}
				ans = append(ans, temp)
				lo1, hi1 := lo, hi
				for lo < hi && nums[lo] == nums[lo1] {
					lo++
				}
				for lo < hi && nums[hi] == nums[hi1] {
					hi--
				}
			}
		}
	}
	return ans
}
