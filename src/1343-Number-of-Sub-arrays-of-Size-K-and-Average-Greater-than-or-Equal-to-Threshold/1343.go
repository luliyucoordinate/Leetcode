func numOfSubarrays(arr []int, k int, threshold int) int {
    s, res, t, n := 0, 0, k * threshold, len(arr)
    for i := 0; i < k - 1; i++ {
        s += arr[i]
    }
    
    for l := 0; l < n - k + 1; l++ {
        s += arr[l + k - 1]
        if s >= t {
            res++
        }
        s -= arr[l]
    }
    return res
}