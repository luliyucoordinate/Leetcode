func findBestValue(arr []int, target int) int {
    sort.Ints(arr)
    maxv := arr[len(arr)-1]
    
    for len(arr) > 0 && target >= arr[0] * len(arr) {
        target -= arr[0]
        arr = arr[1:]
    }
    if len(arr) > 0 {
        return int(float64(target)/float64(len(arr)) + 0.49)
    }
    return maxv
}