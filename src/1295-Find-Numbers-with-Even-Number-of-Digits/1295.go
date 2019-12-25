func findNumbers(nums []int) int {
    res := 0
    for _, v := range nums {
        x := 0
        for v != 0 {
            v /= 10
            x++
        }
        if x % 2 == 0 {
            res++
        }
    }
    return res
}