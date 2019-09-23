func smallestCommonElement(mat [][]int) int {
    r, c := len(mat), len(mat[0])
    for i := 0; i < c; i++ {
        for j := 1; j < r; j++ {
            l, p := 0, c - 1
            for l < p {
                mid := (l + p) >> 1
                if mat[j][mid] < mat[0][i] {
                    l = mid + 1
                } else {
                    p = mid
                }
            }
            if mat[j][l] == mat[0][i] {
                continue
            } else {
                goto b;
            }
        }
        return mat[0][i]
        b:;
    }
    return -1
}