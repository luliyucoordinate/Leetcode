func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
    jobs := make([][]int, 0)
    N, res, i, best := len(profit), 0, 0, 0
    for j := 0; j < N; j++ {
        jobs = append(jobs, []int{difficulty[j], profit[j]})
    }
    sort.Slice(jobs, func(i, j int) bool {
        if jobs[i][0] == jobs[j][0] {
            return jobs[i][1] < jobs[j][1]
        }
        return jobs[i][0] < jobs[j][0]
    })
    sort.Ints(worker)
    for _, w := range worker {
        for i < N && w >= jobs[i][0] {
            best = max(best, jobs[i][1])
            i++
        }
        res += best
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}