func numPrimeArrangements(n int) int {
    primes, st := make([]int, n + 1), make([]int, n + 1)
    cnt, MOD := 0, 1000000007
    for i := 2; i <= n; i++ {
        if st[i] == 0 {
            primes[cnt] = i
            cnt++
        }
        for j := 0; primes[j] <= n / i; j++ {
            st[primes[j]*i] = 1
            if i % primes[j] == 0 {
                break
            }
        }
    }
    
    res := 1
    for i := 1; i <= cnt; i++ {
        res = res * i % MOD
    }
    for i := 1; i <= n - cnt; i++ {
        res = res * i % MOD
    }
    return res
}