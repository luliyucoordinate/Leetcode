func minFlips(mat [][]int) int {
    start, r, c := 0, len(mat), len(mat[0])
    d := []int{0, 0, 1, 0, -1, 0}
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            start |= mat[i][j] << (i * c + j)
        }
    }

    q := []int{start}
    seen := make(map[int]bool)
    for step := 0; len(q) > 0; step++ {
        for qs := len(q); qs > 0; qs-- {
            cur := q[0]
            q = q[1:]
            if cur == 0 {
                return step
            }
            for i := 0; i < r; i++ {
                for j := 0; j < c; j++ {
                    ne := cur
                    for k := 0; k < 5; k++ {
                        x, y := d[k] + i, d[k+1] + j
                        if x >= 0 && x < r && y >= 0 && y < c {
                            ne ^= 1 << (x * c + y)
                        }
                    }
                    if _, ok := seen[ne]; !ok {
                        seen[ne] = true
                        q = append(q, ne)
                    }
                }
            }
        }
    }    
    return -1
}