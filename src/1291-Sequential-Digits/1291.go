func sequentialDigits(low int, high int) []int {
    res := make([]int, 0)
    for i := 1; i < 9; i++ {
        x := i
        for x <= high {
            r := x % 10
            if r == 0 {
                break
            }
            if x >= low {
                res = append(res, x)
            }
            x = x * 10 + r + 1
        }
    }
    sort.Ints(res)
    return res
}