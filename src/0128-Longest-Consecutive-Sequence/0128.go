package longestconsecutivesequence

func longestConsecutive(nums []int) int {
	mp := make(map[int]bool)
	for _, val := range nums {
		mp[val] = true
	}
	ans := 0
	for _, val := range nums {
		_, ex := mp[val-1]
		if !ex {
			curr_val, count := val, 0
			for mp[curr_val] {
				curr_val += 1
				count += 1
			}
			if count > ans {
				ans = count
			}
		}
	}
	return ans
}
