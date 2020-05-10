var m, n int

func kthSmallest(mat [][]int, k int) int {
    m, n = len(mat), len(mat[0])
    l, r, res := m, m * 5000, -1
    
    for l < r {
        mid := (l + r + 1) >> 1
        cnt := dfs(mat, 0, mid, 0, k)
        if cnt >= k {
            res, r = mid, mid - 1
        } else {
            l = mid
        }
    }
    return res
}

func dfs(mat [][]int, cur, target, r, k int) int {
    if cur > target {
        return 0
    }
    if r == m {
        return 1
    }
    
    res := 0
    for c := 0; c < n; c++ {
        cnt := dfs(mat, cur + mat[r][c], target, r + 1, k - res)
        if cnt == 0 {
            break
        }
        res += cnt
        if res > k {
            break
        }
    }
    return res
}