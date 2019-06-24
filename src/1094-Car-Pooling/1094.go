type interval [][]int

func (s interval) Len() int {
    return len(s)
}

func (s interval) Less(i, j int) bool {
    if s[i][0] == s[j][0] {
        return s[i][1] < s[j][1]
    }
    return s[i][0] < s[j][0]
}

func (s interval) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func carPooling(trips [][]int, capacity int) bool {
    tmp := make([][]int, 0)
    for _, v := range trips {
        tmp = append(tmp, []int{v[1], v[0]})
        tmp = append(tmp, []int{v[2], -v[0]})
    }
    
    sort.Sort(interval(tmp))
    n := 0
    for _, v := range tmp {
        n += v[1]
        fmt.Println(n)
        if n > capacity {
            return false
        }
    }
    return true
}