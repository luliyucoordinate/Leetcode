func arrayRankTransform(arr []int) []int {
    arrs := make([]int, len(arr))
    copy(arrs, arr)
    sort.Ints(arrs)
    st := make(map[int]int)
    
    for i := 0; i < len(arrs); i++ {
        if _, ok := st[arrs[i]]; !ok {
            st[arrs[i]] = len(st) + 1
        }
    }
    
    for i := 0; i < len(arr); i++ {
        arr[i] = st[arr[i]]
    }
    return arr
}