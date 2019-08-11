func dayOfYear(date string) int {
    d := strings.Split(date, "-")
    Y, _ := strconv.Atoi(d[0])
    M, _ := strconv.Atoi(d[1])
    res, _ := strconv.Atoi(d[2])
    days := []int{31,28,31,30,31,30,31,31,30,31,30,31}
    if Y % 400 == 0 || Y % 4 == 0 && Y % 100 != 0 {
        days[1]++
    }
    for i := 0; i < M - 1; i++ {
        res += days[i]
    }
    return res
}