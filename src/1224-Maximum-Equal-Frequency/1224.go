func maxEqualFreq(nums []int) int {
    n, res := len(nums), 0
    k := make([]int, n + 1)
    f := make(map[int]int)
    for i := 1; i <= n; i++ {
        a := nums[i - 1]
        k[f[a]]--
        f[a]++
        k[f[a]]++
        t := f[a]
        if k[t] * t == i && i < n {
            res = i + 1
        } else {
            d := i - k[t] * t
            if (d == 1 || d == t + 1) && k[d] == 1 {
                res = i
            }
        }
    }
    return res
}