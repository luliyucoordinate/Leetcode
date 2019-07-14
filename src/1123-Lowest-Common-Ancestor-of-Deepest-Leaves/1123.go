func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    _, res := dfs(root)
    return res
}

func dfs(root *TreeNode) (int, *TreeNode) {
    if root == nil {
        return 0, nil
    }
    ld, lx := dfs(root.Left)
    rd, rx := dfs(root.Right)
    if ld < rd {
        return rd + 1, rx
    } else if ld > rd {
        return ld + 1, lx
    } else {
        return ld + 1, root
    }
}