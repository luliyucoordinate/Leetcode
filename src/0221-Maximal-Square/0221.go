func maximalSquare(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    res, r, c := 0, len(matrix), len(matrix[0])
    mem := make([][]int, r)
    for i := 0; i < r; i++ {
        mem[i] = make([]int, c)
    }
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if i == 0 || j == 0 || matrix[i][j] == '0' {
                mem[i][j] = int(matrix[i][j]) - int('0')
            } else {
                mem[i][j] = min(mem[i][j-1], min(mem[i-1][j], mem[i-1][j-1])) + 1
            }
            res = max(res, mem[i][j])
        }
    }
    return res * res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}