var total, res int64

func maxProduct(root *TreeNode) int {
    total, res = 0, 0
    total = dfs(root)
    total = dfs(root)
    return (int)(res) % 1000000007
}

func dfs(root *TreeNode) int64 {
    if root == nil {
        return 0
    }
    sub := (int64)(root.Val) + dfs(root.Left) + dfs(root.Right)
    res = max(res, sub * (total - sub))
    return sub
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}