package containsduplicateii

func containsNearbyDuplicate(nums []int, k int) bool {
	mp := make(map[int]int, 0)
	for i, v := range nums {
		if val, ok := mp[v]; ok {
			if i-val <= k {
				return true
			}
		}
		mp[v] = i
	}
	return false
}
