func findMinFibonacciNumbers(k int) int {
    res, a, b := 0, 1, 1
    for b <= k {
        a, b = b, a + b
    }

    for a > 0 {
        if a <= k {
            k -= a
            res++
        }
        a, b = b - a, a
    }
    return res
}