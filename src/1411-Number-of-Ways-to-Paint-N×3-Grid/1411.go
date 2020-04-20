func numOfWays(n int) int {
    var aba, abc, mod int64
    aba, abc, mod = 6, 6, 1000000007
    for i := 0; i < n - 1; i++ {
        aba, abc = (aba * 3 + abc * 2) % mod, (aba * 2 + abc * 2) % mod
    }
    return int((aba + abc) % mod)
}