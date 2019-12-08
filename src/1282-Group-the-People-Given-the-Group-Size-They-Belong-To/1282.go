func groupThePeople(a []int) [][]int {
    res := make([][]int, 0)
    data := make(map[int][]int)
    for i, v := range a {
        data[v] = append(data[v], i)
        if len(data[v]) == v {
            res = append(res, data[v])
            data[v] = make([]int, 0)
        }
    }
    return res
}