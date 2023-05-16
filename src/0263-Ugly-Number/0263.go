package uglynumber

func isUgly(n int) bool {
	if n == 0 {
		return false
	}
	fact := [3]int{2, 3, 5}
	for i := 0; i < len(fact); i++ {
		for n%fact[i] == 0 {
			n /= fact[i]
		}
	}
	if n == 1 {
		return true
	}
	return false
}
