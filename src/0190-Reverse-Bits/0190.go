package reversebits

func reverseBits(num uint32) uint32 {
	var ans uint32 = 0
	for i := 0; i < 32; i++ {
		val := num & (1 << i)
		if val != 0 {
			ans |= (1 << (31 - i))
		}
	}
	return ans
}
