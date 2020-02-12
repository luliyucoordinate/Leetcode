var d, match [][]int
var r, c int

func maxStudents(seats [][]byte) int {
    r, c =len(seats), len(seats[0])
    d = [][]int{{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}}
    match = make([][]int, r * c)
    res, cnt := 0, 0
    
    vis := make([]bool, r * c)
    for i := 0; i < r; i++ {
        for j := 0; j < c; j += 2 {
            if seats[i][j] != '.' {
                continue
            }
            for k := 0; k < r * c; k++ {
                vis[k] = false
            }
            node := []int{i, j}
            if find(node, vis, seats) {
                res++
            }
        }
    }

    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if seats[i][j] == '.' {
                cnt++
            }
        }
    }
    return cnt - res
}

func find(node []int, vis []bool, seats[][]byte) bool {
    for _, it := range d {
        nx, ny := node[0] + it[0], node[1] + it[1]
        if nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx * c + ny] && seats[nx][ny] == '.' {
            vis[nx * c + ny] = true
            if match[nx * c + ny] == nil || find(match[nx * c + ny], vis, seats) {
                match[nx * c + ny] = node
                return true
            }
        }
    }
    return false
}