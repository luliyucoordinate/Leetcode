package maximumproductsubarray

func maxProduct(nums []int) int {
	ans, mx, mn, temp := nums[0], nums[0], nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		mx = max(nums[i], max(nums[i]*mx, nums[i]*mn))
		mn = min(nums[i], min(nums[i]*temp, nums[i]*mn))
		temp = mx
		ans = max(ans, mx)
	}
	return ans
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
