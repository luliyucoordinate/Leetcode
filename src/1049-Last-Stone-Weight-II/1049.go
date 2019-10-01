func lastStoneWeightII(stones []int) int {
    sum := 0
    for _, v := range stones {
        sum += v
    }
    
    mem := make([]int, (sum >> 1) + 1)
    mem[0] = 1
    for _, i := range stones {
        for j := sum >> 1; j >= i; j-- {
            mem[j] |= mem[j - i]
        }
    }
    for i := sum >> 1; i > 0; i-- {
        if mem[i] > 0 {
            return sum - 2*i
        }
    }
    return 0
}