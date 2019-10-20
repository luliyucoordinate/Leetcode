func checkStraightLine(c [][]int) bool {
    for i := 2; i < len(c); i++ {
        if (c[i][0] - c[0][0]) * (c[i][1] - c[1][1]) != (c[i][0] - c[1][0]) * (c[i][1] - c[0][1]) {
            return false
        }
    }
    return true
}