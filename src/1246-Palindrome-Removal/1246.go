func minimumMoves(arr []int) int {
    n := len(arr)
    mem := make([][]int, n + 1)
    for i := 0; i <= n; i++ {
        mem[i] = make([]int, n + 1)
    }
    for l := 1; l <= n; l++ {
        i, j := 0, l - 1
        for j < n {
            if l == 1 {
                mem[i][j] = 1 + mem[i + 1][j]
            } else {
                mem[i][j] = 1 + mem[i + 1][j]
                for k := i + 1; k <= j; k++ {
                    if arr[k] == arr[i] {
                        tmp := mem[i + 1][k - 1] + mem[k + 1][j]
                        if i + 1 == k {
                            tmp++
                        }
                        mem[i][j] = min(mem[i][j], tmp)
                    }
                }
            }
            i++
            j++
        }
    }
    return mem[0][n - 1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}