func sumSubseqWidths(A []int) int {
    sort.Sort(IntSlice(A))
    res, n, mod := 0, len(A), 1000000007
    for i := 0; i < n; i++ {
        res *= 2
        res -= A[i]
        res += A[n - i - 1]
        res %= mod
    }
    return (res + mod) % mod
}

type IntSlice []int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return s[i] < s[j]
}