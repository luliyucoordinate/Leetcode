func queensAttacktheKing(queens [][]int, king []int) [][]int {
    g := make([][]int, 8)
    for i := 0; i < 8; i++ {
        g[i] = make([]int, 8)
    }
    for _, i := range queens {
        g[i[0]][i[1]] = 1
    }
    
    res := make([][]int, 0)
    for i := -1; i <= 1; i++ {
        for j := -1; j <= 1; j++ {
            for k := 1; k < 8; k++ {
                x, y := king[0] + i*k, king[1] + j*k
                if x >= 0 && y >= 0 && x < 8 && y < 8 && g[x][y] == 1{
                    res = append(res, []int{x, y})
                    break
                }
            } 
        }
    }
    return res
}