func isArmstrong(N int) bool {
    str := strconv.Itoa(N)
    n := len(str)
    var res float64 = 0
    for _, v := range []byte(str) {
        t, _ := strconv.ParseFloat(string(v), 64)
        res += math.Pow(t, float64(n))
    }
    return int(res) == N
}