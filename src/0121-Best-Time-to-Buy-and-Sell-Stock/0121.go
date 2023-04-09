package main

func maxProfit(prices []int) int {
	ans, mx := 0, prices[len(prices)-1]
	for i := len(prices) - 2; i >= 0; i-- {
		ans = max(ans, mx-prices[i])
		mx = max(mx, prices[i])
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
