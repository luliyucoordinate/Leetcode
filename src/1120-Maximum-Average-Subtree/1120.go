var res float64
func maximumAverageSubtree(root *TreeNode) float64 {
    res = 0.0
    dfs(root)
    return res
}

func dfs(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    v1, n1 := dfs(root.Left)
    v2, n2 := dfs(root.Right)
    v := v1 + v2 + root.Val
    n := n1 + n2 + 1
    res = math.Max(res, float64(v)/float64(n))
    return v, n
}