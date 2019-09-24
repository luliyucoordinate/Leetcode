func minimumAbsDifference(arr []int) [][]int {
    sort.Sort(IntSlice(arr))
    res := make([][]int, 0)
    min_dif := 10000000
    for i := 1; i < len(arr); i++ {
        dif := arr[i] - arr[i-1]
        if dif > min_dif {
            continue
        } else if dif < min_dif {
            min_dif = dif
            res = res[0:0]
        }
        res = append(res, []int{arr[i-1], arr[i]})
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