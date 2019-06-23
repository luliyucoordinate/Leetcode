func sampleStats(count []int) []float64 {
    res := make([]float64, 5)
    res[0] = 255
    sum_all := 0
    for _, val := range count {
        sum_all += val
    }
    
    l, r := sum_all/2, sum_all/2
    if (sum_all % 2) == 0 {
        r++
    }
    
    pre, lc := 0, 0
    for i, val := range count {
        if val > 0 {
            if i < int(res[0]) {
                res[0] = float64(i)
            }
            res[1] = float64(i)
        }
        res[2] += float64(i * val)/float64(sum_all)
        if pre < l && pre + val >= l {
            res[3] += float64(i)/2.0
        }
        if pre < r && pre + val >= r {
            res[3] += float64(i)/2.0
        }
        pre += val
        
        if val > lc {
            lc = val
            res[4] = float64(i)
        }
    }
    return res
}