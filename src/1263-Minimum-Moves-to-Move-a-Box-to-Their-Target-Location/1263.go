var r, c int
var B, S, T []int
var dire [][]int

func minPushBox(grid [][]byte) int {
    r, c = len(grid), len(grid[0])
    dire = [][]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == 'T' {
                T = []int{i, j}
            } else if grid[i][j] == 'B' {
                B = []int{i, j}
            } else if grid[i][j] == 'S' {
                S = []int{i, j}
            }
        }
    }    

    res := 0
    q := [][]int{{B[0], B[1], S[0], S[1]}}
    var vis [21][21][21][21]bool
    vis[B[0]][B[1]][S[0]][S[1]] = true
    for len(q) > 0 {
        n := len(q)
        for k := 0; k < n; k++ {
            p := q[0]
            q = q[1:]
            if p[0] == T[0] && p[1] == T[1] {
                return res
            }

            for _, it := range dire {
                nx, ny := it[0] + p[0], it[1] + p[1]
                e := []int{p[0] - it[0], p[1] - it[1]}
                b := []int{p[0], p[1]}
                s := []int{p[2], p[3]}
                if check(nx, ny, grid) && check(e[0], e[1], grid) && !vis[nx][ny][p[0]][p[1]] && canMoveTo(e, b, s, grid) {
                    q = append(q, []int{nx, ny, p[0], p[1]})
                    vis[nx][ny][p[0]][p[1]] = true
                }
            }
        }
        res++
    }
    return -1
}

func check(x, y int, grid [][]byte) bool {
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#'
}

func canMoveTo(e, b, s []int, grid [][]byte) bool {
    q := [][]int{s}
    var vis [21][21]bool
    vis[s[0]][s[1]] = true
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        if pre[0] == e[0] && pre[1] == e[1]{
            return true
        } 

        for _, it := range dire {
            nx, ny := pre[0] + it[0], pre[1] + it[1];
            if check(nx, ny, grid) && (nx != b[0] || ny != b[1]) && !vis[nx][ny] {
                q = append(q, []int{nx, ny})
                vis[nx][ny] = true;
            }
        }
    }
    return false
}