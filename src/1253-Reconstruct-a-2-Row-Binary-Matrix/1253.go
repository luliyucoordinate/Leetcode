func reconstructMatrix(u int, l int, cs []int) [][]int {
    res := make([][]int, 2)
    for i := 0; i < 2; i++ {
        res[i] = make([]int, len(cs))
    }
    for i := 0; i < len(cs); i++ {
        if cs[i] == 2 || (cs[i] == 1 && l < u) {
            res[0][i] = 1
            u--
        } else {
            res[0][i] = 0
        }
        if cs[i] == 2 || (cs[i] == 1 && res[0][i] == 0) {
            res[1][i] = 1
            l--
        } else {
            res[1][i] = 0
        }
    }
    if l == 0 && u == 0 {
        return res
    }
    return [][]int{}
}