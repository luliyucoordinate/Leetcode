func gardenNoAdj(N int, paths [][]int) []int {
    res := make([]int, N)
    m := make([][]int, N + 1)
    for _, it := range paths {
        m[it[0]] = append(m[it[0]], it[1])
        m[it[1]] = append(m[it[1]], it[0])
    }
    
    for i := 1; i <= N; i++ {
        used := make([]bool, 5)
        for _, j := range m[i] {
            used[res[j - 1]] = true
        }
        
        for j := 1; j < 5; j++ {
            if !used[j] {
                res[i - 1] = j
                break
            }
        }
    }
    return res
}