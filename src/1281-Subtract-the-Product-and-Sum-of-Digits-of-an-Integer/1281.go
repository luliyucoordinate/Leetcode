func subtractProductAndSum(n int) int {
    sum, product := 0, 1
    for n > 0 {
        sum += n % 10
        product *= n % 10
        n /= 10
    }
    return product - sum
}