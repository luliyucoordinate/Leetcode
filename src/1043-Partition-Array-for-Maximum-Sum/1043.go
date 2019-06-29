func maxSumAfterPartitioning(A []int, K int) int {
    n := len(A)
    mem := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        cur := 0
        for j := 1; j <= K; j++ {
            if i >= j {
                if cur < A[i - j] {
                    cur = A[i - j]
                }
                if mem[i] < mem[i - j] + cur * j {
                    mem[i] = mem[i - j] + cur * j
                }
            }
        }
    }
    return mem[n]
}