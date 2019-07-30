const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX
var mem [][]int
var n int

func stoneGameII(piles []int) int {
    n = len(piles)
    mem = make([][]int, n)
    for i := 0; i < n; i++ {
        mem[i] = make([]int, n)
        for j := 0; j < n; j++ {
            mem[i][j] = INT_MAX
        }
    }
    
    for i := n - 2; i >= 0; i-- {
        piles[i] += piles[i + 1]
    }
    
    return dfs(0, 1, &piles)
}

func dfs(i, m int, piles *[]int) int {
    if mem[i][m] != INT_MAX {
        return mem[i][m]
    }
    if i + 2 *m >= n {
        return (*piles)[i]
    }
    
    res := INT_MIN
    for x := 1; x <= 2 * m; x++ {
        res = max(res, (*piles)[i] - dfs(i + x, max(x, m), piles))
    }
    mem[i][m] = res
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}