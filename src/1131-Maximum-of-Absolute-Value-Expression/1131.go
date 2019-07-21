func maxAbsValExpr(arr1 []int, arr2 []int) int {
    res, n := 0, len(arr1)
    dire := [][]int{{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    for _, v := range dire {
        r := arr1[0] * v[0] + arr2[0] * v[1];
        for i := 0; i < n; i++ {
            l := arr1[i] * v[0] + arr2[i] * v[1] + i;
            if l - r > res {
                res = l - r
            }
            if l < r {
                r = l
            }
        }
    }
    return res
}