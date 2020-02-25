func closestDivisors(num int) []int {
    for i := int(math.Sqrt(float64(num + 2))); i > 0; i-- {
        if (num + 1) % i == 0 {
            return []int{i, (num + 1) / i}
        }
        if (num + 2) % i == 0 {
            return []int{i, (num + 2) / i}
        }
    }
    return []int{}
}