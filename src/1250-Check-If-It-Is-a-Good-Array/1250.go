func isGoodArray(nums []int) bool {
    x, y := nums[0], 0
    for _, a := range nums {
        for a > 0 {
            y, x = x % a, a
            a = y
        }
    }
    return x == 1
}