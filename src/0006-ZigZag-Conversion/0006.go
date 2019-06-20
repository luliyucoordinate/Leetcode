func convert(s string, numRows int) string {
    if numRows == 1 || len(s) < numRows {
        return s
    }
    
    res := make([]uint8, len(s))
	v := 0
	for i := 0; i < numRows; i++ {
		for k := i; k < len(s); k += (numRows - 1)*2 {
			res[v] = s[k]
			v++
			if i != 0 && i != numRows - 1 {
				next := k + (numRows - i - 1)*2
				if next < len(s) {
					res[v] = s[next]
					v++
				}
			}
		}
	}
	return string(res)
}