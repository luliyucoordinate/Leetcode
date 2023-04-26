package dailytemperatures

func dailyTemperatures(temperatures []int) []int {
	ans := make([]int, len(temperatures), cap(temperatures))
	if len(temperatures) == 0 {
		return ans
	}
	st := make([]int, 0, len(temperatures))
	for i := len(temperatures) - 1; i >= 0; i-- {
		for len(st) > 0 && temperatures[i] >= temperatures[st[len(st)-1]] {
			st = st[:len(st)-1]
		}
		if len(st) == 0 {
			ans[i] = 0
		} else {
			ans[i] = st[len(st)-1] - i
		}
		st = append(st, i)
	}
	return ans
}
