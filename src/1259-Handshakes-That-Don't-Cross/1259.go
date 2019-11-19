func numberOfWays(n int) int {
    inv := make([]int, n / 2 + 2)
    inv[1] = 1
    mod, res := 1000000007, 1
    for i := 2; i < n / 2 + 2; i++ {
        inv[i] = mod - mod / i * inv[mod%i]%mod
    }
    for i := 1; i < n / 2 + 1; i++ {
        res = res * (i + n / 2) % mod
        res = res * inv[i] % mod
    }
    return res * inv[n / 2 + 1] % mod
}