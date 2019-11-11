func oddCells(n int, m int, indices [][]int) int {
    row := make([]int, n)
    col := make([]int, m)
    rowCnt, colCnt := 0, 0
    for _, it := range indices {
        row[it[0]] ^= 1;
        col[it[1]] ^= 1;
        if row[it[0]] == 1 {
            rowCnt++
        } else {
            rowCnt--
        }
        if col[it[1]] == 1 {
            colCnt++
        } else {
            colCnt--
        }
    }
    return m * rowCnt + n * colCnt - rowCnt * colCnt * 2
}