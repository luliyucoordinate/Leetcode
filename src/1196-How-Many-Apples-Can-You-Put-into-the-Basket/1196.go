func maxNumberOfApples(arr []int) int {
    sort.Sort(IntSlice(arr))
    res, t := 0, 0
    for _, v := range arr {
        t += v
        if t > 5000 {
            break
        }
        res++
    }
    return res
}

type IntSlice []int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return s[i] < s[j]
}