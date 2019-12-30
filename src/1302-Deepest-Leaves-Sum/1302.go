func deepestLeavesSum(root *TreeNode) int {
    q := []*TreeNode{root}
    res := 0
    
    for len(q) > 0 {
        n := len(q)
        res = 0
        for i := 0; i < n; i++ {
            cur := q[0]
            q = q[1:]
            res += cur.Val
            if cur.Left != nil {
                q = append(q, cur.Left)
            }
            if cur.Right != nil {
                q = append(q, cur.Right)
            }
        }
    }
    return res
}