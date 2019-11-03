func transformArray(arr []int) []int {
    change, n := true, len(arr)
    tmp := make([]int, n)
    copy(tmp, arr)
    for change {
        change = false
        for i := 1; i < n -1; i++ {
            if arr[i] > arr[i-1] && arr[i] > arr[i+1] {
                tmp[i]--
                change = true;
            } else if arr[i] < arr[i-1] && arr[i] < arr[i+1] {
                tmp[i]++
                change = true;
            } 
        }
        copy(arr, tmp)
    }
    return arr
}