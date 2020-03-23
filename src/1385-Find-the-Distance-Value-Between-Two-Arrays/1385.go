func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
    sort.Ints(arr2)
    
    res := 0
    for _, x := range arr1 {
        if check(arr2, x, d) {
            res++
        }
    }
    return res
}

func check(arr2 []int, x int, d int) bool {
    l, r := 0, len(arr2) - 1
    for l < r {
        mid := (l + r) >> 1
        if abs(arr2[mid] - x) <= d {
            return false
        }
        if arr2[mid] > x {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return abs(arr2[l] - x) > d
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
} 