func jobScheduling(startTime []int, endTime []int, profit []int) int {
    n := len(startTime)
    jobs := make([][]int, 0)
    for i := 0; i < n; i++ {
        jobs = append(jobs, []int{startTime[i], endTime[i], profit[i]})
    }
    sort.Slice(jobs, func(i, j int) bool {
        return jobs[i][1] < jobs[j][1]
    })
    dp := make([]int, n)
    dp[0] = jobs[0][2]
    
    for i := 1; i < n; i++ {
        l, r := 0, i - 1
        for l < r {
            mid := (l + r + 1) >> 1
            if jobs[mid][1] <= jobs[i][0] {
                l = mid 
            } else {
                r = mid - 1
            }
        }
        if jobs[l][1] <= jobs[i][0] {
            dp[i] = max(dp[i - 1], dp[l] + jobs[i][2]);
        } else {
            dp[i] = max(dp[i - 1], jobs[i][2]);
        } 
    }
    return dp[n - 1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}