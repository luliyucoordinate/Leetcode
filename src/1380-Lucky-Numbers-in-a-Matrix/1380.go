func luckyNumbers (A [][]int) []int {
    r, c := len(A), len(A[0])
    res := []int{}
    
    for i := 0; i < r; i++ {
        minv, minp := 100000, -1
        for j := 0; j < c; j++ {
            if minv > A[i][j] {
                minv, minp = A[i][j], j
            }
        }
        
        flag := false
        for j := 0; j < r; j++ {
            if minv < A[j][minp] {
                flag = true
                break
            }
        }
        
        if !flag {
            res = append(res, minv)
        }        
    }
    return res
}