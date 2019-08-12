func numRollsToTarget(d int, f int, target int) int {
    mem := make([]int, target + 1)
    mem[0] = 1
    for i := 0; i < d; i++ {
        tmp := make([]int, target + 1)
        for j := 1; j <= f; j++ {
            for k := j; k <= target; k++ {
                tmp[k] = (tmp[k] + mem[k - j]) % 1000000007
            }
        }
        mem = tmp
    }
    return mem[target]
}