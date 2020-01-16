func getNoZeroIntegers(n int) []int {
    for a := 1; a < n; a++ {
        b := n - a
        if !strings.Contains(strconv.Itoa(a), "0") && !strings.Contains(strconv.Itoa(b), "0") {
            return []int{a, b}
        }
    }
    return []int{}
}