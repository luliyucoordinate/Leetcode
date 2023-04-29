package majorityelement

func majorityElement(nums []int) int {
	mp := make(map[int]int, 0)
	ans, mx := -1, -1
	for _, v := range nums {
		mp[v]++
		if mp[v] > mx {
			mx = mp[v]
			ans = v
		}
	}
	return ans
}
