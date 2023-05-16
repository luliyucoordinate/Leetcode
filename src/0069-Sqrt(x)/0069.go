package main

func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	lo, hi, mid, ans := 0, x, 0, 0
	for lo <= hi {
		mid = lo + (hi-lo)/2
		if mid*mid <= x {
			lo = mid + 1
			ans = mid
		} else {
			hi = mid - 1
		}
	}
	return ans
}
