func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    d := make([]int, n)
    for _, i := range leftChild {
        if i != -1 {
            d[i]++
        }
    }
    for _, i := range rightChild {
        if i != -1 {
            d[i]++
        }
    }
    
    root := -1
    for i := 0; i < n; i++ {
        if d[i] == 0 {
            if root != -1 {
                return false
            }
            root = i
        }
    }
    if root == -1 {
        return false
    }
    
    vis := make(map[int]int)
    q := []int{root}
    vis[root] = 1
    
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        if leftChild[pre] != -1 {
            if _, ok := vis[leftChild[pre]]; ok {
                return false
            }
            vis[leftChild[pre]] = 1
            q = append(q, leftChild[pre])
        }
        if rightChild[pre] != -1 {
            if _, ok := vis[rightChild[pre]]; ok {
                return false
            }
            vis[rightChild[pre]] = 1
            q = append(q, rightChild[pre])
        }
    }
    return len(vis) == n
}