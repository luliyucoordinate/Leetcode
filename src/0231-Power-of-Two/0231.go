package poweroftwo

func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	val := n & (n - 1)
	if val == 0 {
		return true
	}
	return false
}
