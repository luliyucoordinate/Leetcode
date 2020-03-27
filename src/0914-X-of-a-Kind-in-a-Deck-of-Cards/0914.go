func hasGroupsSizeX(deck []int) bool {
    cnt := make([]int, 10000)
    for _, d := range deck {
        cnt[d]++
    }

    res := -1
    for i := 0; i < 10000; i++ {
        if cnt[i] > 0 {
            if res == -1 {
                res = cnt[i]
            } else {
                res = gcd(res, cnt[i])
            }
        }
    }
    return res >= 2
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}