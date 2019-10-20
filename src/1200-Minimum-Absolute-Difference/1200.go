func minimumAbsDifference(arr []int) [][]int {
    sort.Ints(arr)
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