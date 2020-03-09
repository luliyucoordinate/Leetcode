func findTheLongestSubstring(s string) int {
    vowels := make([]int, 26)
    vowels[0] = 1
    vowels[4] = 2
    vowels[8] = 4
    vowels[14] = 8
    vowels[20] = 16
    
    vis := make([]int, 32)
    vis[0] = 1
    res, cur := 0, 0
    for i := 0; i < len(s); i++ {
        cur ^= vowels[s[i] - 'a']
        if vis[cur] == 0 {
            vis[cur] = i + 2
        }
        res = max(res, i - vis[cur] + 2)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}