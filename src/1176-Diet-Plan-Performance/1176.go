func dietPlanPerformance(calories []int, k int, lower int, upper int) int {
    cnt, res := 0, 0
    for i := 0; i < k; i++ {
        cnt += calories[i]
    }
    
    if cnt > upper {
        res++
    } else if cnt < lower {
        res--
    }
    for i := k; i < len(calories); i++ {
        cnt += calories[i] - calories[i - k]
        if cnt > upper {
            res++
        } else if cnt < lower {
            res--
        }
    }
    return res
}