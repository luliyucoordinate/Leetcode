func eraseOverlapIntervals(intervals [][]int) int {
    if len(intervals) == 0 {
        return 0
    }
    sort.Sort(IntSlice(intervals))
    res, pre := 0, intervals[0]
    for _, cur := range intervals[1:] {
        if pre[1] > cur[0] {
            res++
            if pre[1] > cur[1] {
                pre = cur
            }
        } else {
            pre = cur
        }
    }
    return res
}

type IntSlice [][]int

func (s IntSlice) Len() int { 
    return len(s) 
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    if s[i][0] != s[j][0] {
        return s[i][0] < s[j][0]
    }
    return s[i][1] < s[j][1]
}
