var d = [4][2]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}

func maxDistance(grid [][]int) int {
    data := make([][]int, 0)
    r, c := len(grid), len(grid[0])
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == 1 {
                data = append(data, []int{i, j})
            }
        }
    }
    
    if r*c == len(data) || 0 == len(data) {
        return -1
    }
    res := 0
    for len(data) > 0 {
        dataLen := len(data)
        for k := 0; k < dataLen; k++ {
            pre := data[0]
            data = data[1:]
            for _, it := range d {
                x, y := it[0] + pre[0], it[1] + pre[1]
                if x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 0 {
                    grid[x][y] = 1
                    data = append(data, []int{x, y})
                }
            }
        }
        res++
    }
    return res - 1
}