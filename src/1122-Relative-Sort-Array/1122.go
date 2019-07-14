var order []int
func relativeSortArray(arr1 []int, arr2 []int) []int {
    order = make([]int, 1001)
    for i, v := range arr2 {
        order[v] = i + 1
    }
    
    for i, v := range order {
        if v == 0 {
            order[i] = i + 1001
        }
    }
    sort.Sort(IntSlice(arr1))
    return arr1
}

type IntSlice []int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return order[s[i]] < order[s[j]]
}