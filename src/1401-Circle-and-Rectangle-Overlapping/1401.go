func checkOverlap(r int, xc int, yc int, x1 int, y1 int, x2 int, y2 int) bool {
    x, y := (x1 + x2) / 2, (y1 + y2) / 2
    h := []int{x2 - x, y2 - y}
    v := []int{abs(x - xc), abs(y - yc)}
    u := []int{max(v[0] - h[0], 0), max(v[1] - h[1], 0)}
    return r * r >= u[0] * u[0] + u[1] * u[1]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}