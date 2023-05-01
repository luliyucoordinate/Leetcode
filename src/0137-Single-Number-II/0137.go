package singlenumberii

func singleNumber(nums []int) int {
	ans := 0
	for bit := 1; bit != 0; bit <<= 1 {
		count := 0
		for _, num := range nums {
			if num&bit != 0 {
				count++
			}
		}
		if count%3 == 1 {
			ans |= bit
		}
	}
	return ans
}
