func makeArrayIncreasing(arr1 []int, arr2 []int) int {
    l1, l2 := len(arr1), len(arr2)
    sort.Sort(IntSlice(arr2))
    dp := map[int]int{0:arr1[0], 1:arr2[0]}
    for i := 1; i < l1; i++ {
        ndp := make(map[int]int)
        for k, v := range dp {
            if arr1[i] > v {
                if v2, ok := ndp[k]; !ok || v2 > arr1[i] {
                    ndp[k] = arr1[i]
                } 
            }
            l, r := 0, l2 - 1
            for l < r {
                mid := (l + r) >> 1
                if arr2[mid] <= v {
                    l = mid + 1
                } else {
                    r = mid
                }
            }
            if l < l2 && arr2[l] <= v {
                l++
            }
            if l < l2 {
                if v2, ok := ndp[k+1]; !ok || v2 > arr2[l] {
                    ndp[k+1] = arr2[l]
                }
            }
        }
        dp = ndp
    }
    if len(dp) == 0 {
        return -1
    }
    res := 2000
    for k := range dp {
        res = min(res, k)
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

type IntSlice []int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return s[i] < s[j]
}