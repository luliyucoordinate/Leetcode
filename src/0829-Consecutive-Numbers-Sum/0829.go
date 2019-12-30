func consecutiveNumbersSum(N int) int {
    res, i := 1, 3
    for N % 2 == 0 {
        N >>= 1
    }
    
    for i * i <= N {
        cnt := 0
        for N % i == 0 {
            N /= i
            cnt++
        }
        res *= cnt + 1
        i += 2
    }
    
    if N == 1 {
        return res
    }
    return res * 2
}