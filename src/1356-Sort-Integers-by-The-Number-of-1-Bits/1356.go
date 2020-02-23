func sortByBits(arr []int) []int {
    sort.Slice(arr, func(i, j int) bool {
        a, b := bin(arr[i]), bin(arr[j])
        if a == b {
            return arr[i] < arr[j]
        }
        return a < b
    })
    return arr
}

func bin(x int) int {
    res := 0
    for x > 0 {
        x = x & (x - 1)
        res++
    }
    return res
}