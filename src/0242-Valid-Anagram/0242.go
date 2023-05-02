package validanagram

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	mp := make(map[rune]int, 0)
	for _, v := range s {
		mp[v]++
	}
	for _, v := range t {
		mp[v]--
		if mp[v] < 0 {
			return false
		}
	}
	return true
}
