var son map[int][]int

func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
    son = make(map[int][]int)
    for i, v := range manager {
        son[v] = append(son[v], i)
    }
    return dfs(headID, informTime)
}

func dfs(x int, informTime []int) int {
    res := 0
    for _, n := range son[x] {
        res = max(res, dfs(n, informTime))
    }
    return res + informTime[x]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}