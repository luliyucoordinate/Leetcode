package containsduplicate

func containsDuplicate(nums []int) bool {
	mp := make(map[int]bool)
	for _, val := range nums {
		if _, ok := mp[val]; ok == true {
			return true
		}
		mp[val] = true
	}
	return false
}
