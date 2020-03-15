func numSubmatrixSumTarget(A [][]int, target int) int {
    r, c := len(A), len(A[0])
    for _, row := range A {
        for i := 1; i < c; i++ {
            row[i] += row[i - 1]
        }
    }
    
    res, cur := 0, 0
    for i := 0; i < c; i++ {
        for j := i; j < c; j++ {
            cnt := make(map[int]int)
            cnt[0] = 1
            cur = 0
            for k := 0; k < r; k++ {
                if i > 0 {
                    cur += A[k][j] - A[k][i - 1]
                } else {
                    cur += A[k][j]
                }
                res += cnt[cur - target]
                cnt[cur]++
            }
        }
    }
    return res
}