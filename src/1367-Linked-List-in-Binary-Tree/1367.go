var arr, f []int

func isSubPath(head *ListNode, root *TreeNode) bool {
    arr, f = []int{}, []int{-1}
    i, node := -1, head
    
    for node != nil {
        for i != -1 && node != nil && node.Val != arr[i] {
            i = f[i]
        }
        i++
        
        arr = append(arr, node.Val)
        f = append(f, i)
        node = node.Next
    }
    
    return dfs(root, 0)
}

func dfs(root *TreeNode, u int) bool {
    if root == nil {
        return false
    }
    
    for u != -1 && arr[u] != root.Val {
        u = f[u]
    }
    u++
    
    if u == len(arr) {
        return true
    }
    return dfs(root.Left, u) || dfs(root.Right, u)
}