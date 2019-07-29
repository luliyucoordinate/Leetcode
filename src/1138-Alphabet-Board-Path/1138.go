func alphabetBoardPath(target string) string {
    res := ""
    x, y := 0, 0
    for _, v := range []byte(target) {
        x1, y1 := int(v - 'a') / 5, int(v - 'a') % 5
        l, c := x1 - x, y1 - y
        if c < 0 {
            for i := 0; i < -c; i++ {
                res += "L"
            }
        }
        
        if l < 0 {
            for i := 0; i < -l; i++ {
                res += "U"
            }
        }
        
        if c > 0 {
            for i := 0; i < c; i++ {
                res += "R"
            }
        }
        
        if l > 0 {
            for i := 0; i < l; i++ {
                res += "D"
            }
        }
        res += "!"
        x, y = x1, y1
    }
    return res
}