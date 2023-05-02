package groupanagrams

import "sort"

func groupAnagrams(strs []string) [][]string {
	mp := make(map[string][]string, 0)
	for _, val := range strs {
		byteStr := []byte(val)
		sort.Slice(byteStr, func(i, j int) bool { return byteStr[i] < byteStr[j] })
		sortedStr := string(byteStr)
		mp[sortedStr] = append(mp[sortedStr], val)
	}
	ans := make([][]string, 0)
	for _, val := range mp {
		ans = append(ans, val)
	}
	return ans
}
