func numFriendRequests(ages []int) int {
    cnt := make([]int, 121)
    pre := make([]int, 121)
    for _, a := range ages {
        cnt[a]++
    }
    for i := 1; i < 121; i++ {
        pre[i] = pre[i - 1] + cnt[i]
    }
    res := 0
    for i := 15; i < 121; i++ {
        res += (pre[i] - pre[i/2 + 7] - 1) * cnt[i]
    }
    return res
}