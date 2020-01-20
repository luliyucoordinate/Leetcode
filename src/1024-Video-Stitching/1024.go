func videoStitching(clips [][]int, T int) int {
    sort.Slice(clips, func(i, j int) bool {
        return clips[i][0] < clips[j][0];
    })
    
    pre, cur, step := -1, 0, 0
    for _, it := range clips {
        if cur >= T || it[0] > cur {
            break
        }
        if pre < it[0] && it[0] <= cur {
            step++
            pre = cur
        }
        cur = max(cur, it[1])
    }
    if cur >= T {
        return step
    }
    return -1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}