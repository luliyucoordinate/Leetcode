func countVowelPermutation(n int) int {
    var a, e, i, o, u, mod uint32
    a, e, i, o, u, mod = 1, 1, 1, 1, 1, 1000000007
    for k := 1; k < n; k++ {
        a, e, i, o, u = (e + i + u)%mod, (a + i)%mod, (e + o)%mod, i, (i + o)%mod
    }
    return int((a + e + i + o + u) % mod)
}