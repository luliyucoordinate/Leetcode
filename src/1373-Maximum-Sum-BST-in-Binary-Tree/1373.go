var maxv int

func maxSumBST(root *TreeNode) int {
    maxv = 0
    dfs(root)
    return maxv
}

func dfs(root *TreeNode) (bool, int) {
    if root == nil {
        return true, 0
    }
    
    reb, rev := true, root.Val
    if root.Left != nil {
        ok, l := dfs(root.Left)
        if ok && root.Left.Val < root.Val {
            rev += l
        } else {
            reb = false
        }
    }
    
    if root.Right != nil {
        ok, r := dfs(root.Right)
        if ok && root.Right.Val > root.Val {
            rev += r
        } else {
            reb = false
        }
    }
    
    if reb {
        maxv = max(maxv, rev)
    }
    return reb, rev
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}