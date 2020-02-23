func countOrders(n int) int {
    var res, mod int64
    res, mod = 1, 1000000007
    
    for i := 1; i <= n; i++ {
        res = res * int64((i * 2 - 1) * i) % mod
    }
    return int(res)
}