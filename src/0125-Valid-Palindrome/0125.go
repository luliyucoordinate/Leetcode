package validpalindrome

import "strings"

func isPalindrome(s string) bool {
	s = strings.ToLower(s)
	for i, j := 0, len(s)-1; i < j; {
		if !isAlphaNumeric(s[i]) {
			i++
			continue
		}
		if !isAlphaNumeric(s[j]) {
			j--
			continue
		}
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func isAlphaNumeric(ch byte) bool {
	if ch >= 'a' && ch <= 'z' {
		return true
	} else if ch >= '0' && ch <= '9' {
		return true
	}
	return false
}
