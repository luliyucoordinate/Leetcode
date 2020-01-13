func sumEvenGrandparent(root *TreeNode) int {
    return dfs(root, 1, 1)
}

func dfs(root *TreeNode, p, gp int) int {
    if root == nil {
        return 0
    }
    
    t := 0
    if gp % 2 == 0 {
        t = root.Val
    } 
    return dfs(root.Left, root.Val, p) + dfs(root.Right, root.Val, p) + t
}