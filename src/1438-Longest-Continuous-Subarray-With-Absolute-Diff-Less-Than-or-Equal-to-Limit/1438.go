func longestSubarray(nums []int, limit int) int {
    maxq := make([]int, 0)
    minq := make([]int, 0)
    i := 0

    for _, a := range nums {
        for len(maxq) > 0 && a > maxq[len(maxq) - 1] {
            maxq = maxq[:len(maxq) - 1]
        }
        for len(minq) > 0 && a < minq[len(minq) - 1] {
            minq = minq[:len(minq) - 1]
        }
        maxq = append(maxq, a)
        minq = append(minq, a)

        if maxq[0] - minq[0] > limit {
            if maxq[0] == nums[i] {
                maxq = maxq[1:]
            }
            if minq[0] == nums[i] {
                minq = minq[1:]
            }
            i++
        }
    }
    return len(nums) - i
}