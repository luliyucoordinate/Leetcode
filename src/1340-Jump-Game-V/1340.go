var dp, lb, rb []int
var n, td int

func maxJumps(arr []int, d int) int {
    n, td = len(arr), d
    dp = make([]int, n)
    lb = make([]int, n)
    rb = make([]int, n)
    for i := 0; i < n; i++ {
        lb[i], rb[i] = -1, -1
    }
    
    findBiggerLeft(arr)
    findBiggerRight(arr)

    res := 0
    for i := 0; i < n; i++ {
        res = max(res, dfs(i))
    }
    return res
}

func findBiggerLeft(arr []int) {
    s := []int{}
    for i := 0; i < n; i++ {
        for len(s) > 0 && s[0] < i - td {
            s = s[1:]
        }
        for len(s) > 0 && arr[s[len(s)-1]] <= arr[i] {
            s = s[:len(s)-1]
        }
        if len(s) > 0 {
            lb[i] = s[len(s) - 1]
        }
        s = append(s, i)
    }
}

func findBiggerRight(arr []int) {
    s := []int{}
    for i := 0; i < n; i++ {
        for len(s) > 0 && s[0] < i - td  {
            s = s[1:]
        }
        for len(s) > 0 && arr[s[len(s) - 1]] < arr[i] {
            rb[s[len(s) - 1]] = i
            s = s[:len(s) - 1]
        }
        s = append(s, i)
    }
}

func dfs(u int) int {
    if dp[u] > 0 {
        return dp[u]
    }
    
    dp[u] = 1
    if lb[u] >= 0 {
        dp[u] = max(dp[u], dfs(lb[u]) + 1)
    }
    if rb[u] >= 0 {
        dp[u] = max(dp[u], dfs(rb[u]) + 1)
    }
    return dp[u]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}