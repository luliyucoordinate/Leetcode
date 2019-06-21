func lengthOfLongestSubstring(s string) int {
    dict := make(map[byte]int)
    res, l := 0, 0
    for i, ch := range []byte(s) {
        if it, ok := dict[ch]; ok && l <= it {
            l = it + 1
        }
        if i - l + 1 > res {
            res = i - l + 1
        }
        dict[ch] = i
    }
    return res
}