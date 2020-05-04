func findDiagonalOrder(nums [][]int) []int {
    mat := [][]int{}
    for i := 0; i < len(nums); i++ {
        for j := 0; j < len(nums[i]); j++ {
            if i + j >= len(mat) {
                mat = append(mat, []int{})
            }
            mat[i + j] = append(mat[i + j], nums[i][j])
        }
    }
    
    res := []int{}
    for _, diag := range mat {
        for i := len(diag) - 1; i >= 0; i-- {
            res = append(res, diag[i])
        }
    }
    return res
}