func numOfBurgers(t int, c int) []int {
    if t % 2 == 0 && c * 2 <= t && t <= c * 4 {
        return []int{t / 2 - c, c * 2 - t / 2}
    }
    return []int{}
}