func findSpecialInteger(arr []int) int {
    n := len(arr)
    for i := 0; i < n; i += n / 4 + 1 {
        l, r := bs(arr, true, arr[i]), bs(arr, false, arr[i]) 
        if r - l > n / 4 {
            return arr[i]
        }
    }
    return -1
}

func bs(arr []int, flag bool, t int) int {
    l, r := 0, len(arr)
    for l < r {
        mid := (l + r) >> 1
        if t < arr[mid] || (flag && t == arr[mid]) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}