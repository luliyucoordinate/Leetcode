func arraysIntersection(arr1 []int, arr2 []int, arr3 []int) []int {
    d := make([]int, 2001)
    for _, x := range arr1 {
        d[x]++
    }
    for _, x := range arr2 {
        d[x]++
    }
    
    res := make([]int, 0)
    for _, x := range arr3 {
        if d[x] == 2 {
            res = append(res, x)
        }
    }
    return res
}