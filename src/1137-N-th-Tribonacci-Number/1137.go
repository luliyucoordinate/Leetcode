var dict map[int]int
func tribonacci(n int) int {
    if v, ok := dict[n]; ok {
        return v
    }
    dict = make(map[int]int)
    tri(35)
    return dict[n]
}

func tri(n int) {
    a, b, c, k := 0, 1, 1, 3
    dict[0], dict[1], dict[2] = 0, 1, 1
    for n > 0 {
        t := c
        c, a, b = a + b + c, b, t
        dict[k] = c
        k++
        n--
    }
}