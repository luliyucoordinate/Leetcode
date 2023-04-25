package validparentheses

func isValid(s string) bool {
	st := make([]byte, 0, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == ')' || s[i] == '}' || s[i] == ']' {
			if len(st) == 0 {
				return false
			}
			ch := st[len(st)-1]
			if (s[i] == ')' && ch != '(') || (s[i] == '}' && ch != '{') || (s[i] == ']' && ch != '[') {
				return false
			}
			st = st[:len(st)-1]
		} else {
			st = append(st, s[i])
		}
	}
	if len(st) == 0 {
		return true
	}
	return false
}
