func sumSubseqWidths(A []int) int {
    sort.Ints(A)
    res, n, mod := 0, len(A), 1000000007
    for i := 0; i < n; i++ {
        res *= 2
        res -= A[i]
        res += A[n - i - 1]
        res %= mod
    }
    return (res + mod) % mod
}