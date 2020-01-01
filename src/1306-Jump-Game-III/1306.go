func canReach(arr []int, start int) bool {
    q := []int{start}
    vis := make([]bool, len(arr))
    vis[start] = true
    
    for len(q) > 0 {
        cur := q[0]
        q = q[1:]
        if arr[cur] == 0 {
            return true
        }
        
        vis[cur] = true
        a, b := cur + arr[cur], cur - arr[cur]
        if a >= 0 && a < len(arr) && !vis[a] {
            q = append(q, a)
        }
        if b >= 0 && b < len(arr) && !vis[b] {
            q = append(q, b)
        }
    }
    return false
}