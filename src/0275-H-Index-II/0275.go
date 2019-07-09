func hIndex(citations []int) int {
    l, n, r := 0, len(citations), len(citations) - 1
    for l < r {
        mid := (l + r + 1) / 2
        if citations[mid] <= n - mid {
            l = mid
        } else {
            r = mid - 1
        }
    }
    if l < n && citations[l] < n - l {
        return n - l - 1
    }
    return n - l
}