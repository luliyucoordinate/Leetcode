func maxEqualRowsAfterFlips(matrix [][]int) int {
    m := make(map[string]int)
    res := 0
    var s bytes.Buffer
    
    for _, row := range matrix {
        s.Reset()
        for _, r := range row {
            s.WriteByte(byte(r ^ row[0]))
        }
        str := s.String()
        m[str]++
        res = max(res, m[str])
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}