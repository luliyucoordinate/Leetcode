func findTheCity(n int, edges [][]int, distanceThreshold int) int {
    d := make([][]int, n)
    for i := 0; i < n; i++ {
        d[i] = make([]int, n)
        for j := 0; j < n; j++ {
            if i == j {
                d[i][i] = 0
            } else {
                d[i][j] = 10010 
            }
        }
    }
        
    for _, e := range edges {
        d[e[0]][e[1]], d[e[1]][e[0]] = e[2], e[2]
    }

    for k := 0; k < n; k++ {
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])
            }
        }
    }

    smallest, res := 10010, 0
    for i := 0; i < n; i++ {
        cnt := 0
        for j := 0; j < n; j++ {
            if d[i][j] <= distanceThreshold {
                cnt++
            }
        }
        if cnt <= smallest {
            res, smallest = i, cnt
        }
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}