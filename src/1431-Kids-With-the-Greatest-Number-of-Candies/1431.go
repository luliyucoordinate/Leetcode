func kidsWithCandies(candies []int, extraCandies int) []bool {
    m := 0
    res := []bool{}
    for _, i := range candies {
        m = max(m, i)
    }
    
    for _, i := range candies {
        res = append(res, extraCandies + i >= m)
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}