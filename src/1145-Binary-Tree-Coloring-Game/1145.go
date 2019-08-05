var tl, tr int
func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
    tl, tr = 0, 0
    dfs(root, x)
    return max(tl, max(tr, n - tl - tr - 1)) > n / 2
}
func dfs(root *TreeNode, x int) int {
    if root == nil {
        return 0
    }
    l, r := dfs(root.Left, x), dfs(root.Right, x)
    if root.Val == x{
        tl, tr = l, r
    }
    return l + r + 1
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
} 