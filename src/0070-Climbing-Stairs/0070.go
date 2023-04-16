package climbingstairs

func climbStairs(n int) int {
	if n < 4 {
		return n
	}
	a, b := 2, 3
	for i := 4; i < n+1; i++ {
		temp := b
		b = a + b
		a = temp
	}
	return b
}
