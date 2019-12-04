func tictactoe(moves [][]int) string {
    score := make([][]int, 2)
    for i := 0; i < 2; i++ {
        score[i] = make([]int, 8)
    }
    p := 0
    
    for _, it := range moves {
        score[p][it[0]]++
        score[p][it[1] + 3]++
        score[p][6] += btoi(it[0] == it[1])
        score[p][7] += btoi(it[0] + it[1] == 2)
        for _, x := range score[p] {
            if x == 3 {
                if p == 0 {
                    return "A"
                } else {
                    return "B"
                }
            }
        }
        p ^= 1
    }
    if len(moves) == 9 {
        return "Draw"
    }
    return "Pending"
}

func btoi(b bool) int {
    if b {
        return 1
    }
    return 0
}