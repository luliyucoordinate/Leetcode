var res int

func longestZigZag(root *TreeNode) int {
    res = 0
    dfs(root)
    return res
}

func dfs(root *TreeNode) (int, int) {
    if root == nil {
        return -1, -1
    }
    _, left := dfs(root.Left)
    right, _ := dfs(root.Right)
    res = max(res, max(left + 1, right+ 1))
    return left + 1, right + 1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}