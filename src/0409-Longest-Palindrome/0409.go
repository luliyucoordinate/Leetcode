func longestPalindrome(s string) int {
    cnt := make([]int, 128)
    for _, c := range s {
        cnt[c]++
    }
    
    res := 0
    for _, i := range cnt {
        res += i / 2 * 2
    }
    if res == len(s) {
        return res
    }
    return res + 1
}