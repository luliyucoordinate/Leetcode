func sumFourDivisors(nums []int) int {
    res := 0
    for _, num := range nums {
        res += get_divisors(num)
    }
    return res
}

func get_divisors(x int) int {
    res, cnt := 0, 0
    for i := 1; i * i <= x; i++ {
        if x % i == 0 {
            res += i
            cnt++
            if i * i != x {
                res += x / i 
                cnt++
            }
            if cnt > 4 {
                return 0
            }
        }
    }
    if cnt < 4 {
        return 0
    }
    return res
}