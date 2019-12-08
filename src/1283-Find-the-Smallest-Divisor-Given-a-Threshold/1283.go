func smallestDivisor(A []int, t int) int {
    l, r, m, sum := 1, 1000000, 0, 0
    for l < r {
        m, sum = (l + r) >> 1, 0
        for _, i := range A {
            sum += (i + m - 1) / m
        }
        if sum > t {
            l = m + 1
        } else {
            r = m
        }
    }
    return l
}