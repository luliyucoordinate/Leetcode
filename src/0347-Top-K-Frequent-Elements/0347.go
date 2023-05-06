package topkfrequentelements

func topKFrequent(nums []int, k int) []int {
	mp := make(map[int]int)
	for _, val := range nums {
		mp[val]++
	}
	str := make([][]int, len(nums)+1)
	for k, v := range mp {
		str[v] = append(str[v], k)
	}
	ans := make([]int, 0)
	for i := len(nums); i >= 1; i-- {
		if len(ans) >= k {
			break
		}
		ans = append(ans, str[i]...)
	}
	return ans
}
