func diagonalSort(mat [][]int) [][]int {
    r, c := len(mat), len(mat[0])
    for i := 0; i < r; i++ {
        t, k := []int{}, min(r - i, c)
        for j := 0; j < k; j++ {
            t = append(t, mat[i + j][j])
        }
        sort.Ints(t)
        for j := 0; j < k; j++ {
            mat[i + j][j] = t[j]
        }
    }
    
    for i := 1; i < c; i++ {
        t, k := []int{}, min(c - i, r)
        for j := 0; j < k; j++ {
            t = append(t, mat[j][i + j])
        }
        sort.Ints(t)
        for j := 0; j < k; j++ {
            mat[j][i + j] = t[j]
        }
    }
    return mat
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}