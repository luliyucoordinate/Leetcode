func maxNumberOfApples(arr []int) int {
    sort.Ints(arr)
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