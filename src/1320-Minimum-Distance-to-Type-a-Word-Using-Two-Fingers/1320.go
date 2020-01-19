var dp []int

func minimumDistance(word string) int {
    dp = make([]int, 26)
    sum_dis, max_a := 0, 0
    for i := 0; i < len(word) - 1; i++ {
        a, c := int(word[i] - 'A'), int(word[i + 1] - 'A')
        for b := 0; b < 26; b++ {
            dp[a] = max(dp[a], dp[b] + dis(a, c) - dis(b, c))
        }
        max_a = max(max_a, dp[a])
        sum_dis += dis(a, c)
    }
    return sum_dis - max_a
}

func dis(a, b int) int {
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}