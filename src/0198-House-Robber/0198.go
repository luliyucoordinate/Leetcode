package houserobber

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	dp := make([]int, len(nums)+2)
	dp[0] = 0
	dp[1] = nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i+1] = max(dp[i-1]+nums[i], dp[i])
	}
	return dp[len(nums)]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
