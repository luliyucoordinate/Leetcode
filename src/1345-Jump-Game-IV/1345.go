func minJumps(arr []int) int {
    g := make(map[int][]int)
    values := make(map[int]bool)
    n, step := len(arr), 0
    for i := 0; i < n; i++ {
        if g[arr[i]] == nil {
            g[arr[i]] = []int{}
        } 
        g[arr[i]] = append(g[arr[i]], i)
    }

    vis := make([]bool, n)
    vis[0] = true
    
    q := []int{0}
    for len(q) > 0 {
        k := len(q)
        for k > 0 {
            k--
            
            pre := q[0]
            q = q[1:]
            if pre == n - 1 {
                return step
            }
            
            if pre - 1 >= 0 && !vis[pre - 1] {
                vis[pre - 1] = true
                q = append(q, pre - 1)
            }
            
            if pre + 1 < n && !vis[pre + 1] {
                vis[pre + 1] = true
                q = append(q, pre + 1)
            }
            
            if _, ok := values[arr[pre]]; ok {
                continue
            }
            values[arr[pre]] = true
            for _, i := range g[arr[pre]] {
                if !vis[i] {
                    vis[i] = true
                    q = append(q, i)
                }
            }
        }
        step++
    }
    return step
}