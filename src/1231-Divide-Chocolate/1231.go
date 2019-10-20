func maximizeSweetness(sweetness []int, K int) int {
    s := 0
    for _, v := range sweetness {
        s += v
    }
    l, r := 1, s/(K + 1)
    for l < r {
        mid := (l + r + 1) >> 1
        cur, cuts := 0, 0
        for _, v := range sweetness {
            cur += v
            if cur >= mid {
                cuts++
                cur = 0
            }
        }
        if cuts > K {
            l = mid
        } else {
            r = mid - 1
        }
    }
    return l
}