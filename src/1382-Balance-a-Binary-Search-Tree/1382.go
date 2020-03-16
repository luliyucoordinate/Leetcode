var res []int

func balanceBST(root *TreeNode) *TreeNode {
    res = []int{}
    inOrder(root)
    return sortedToBST(0, len(res) - 1)
}

func inOrder(root *TreeNode) {
    if root != nil {
        inOrder(root.Left)
        res = append(res, root.Val)
        inOrder(root.Right)
    }
}

func sortedToBST(l, r int) *TreeNode {
    if l > r {
        return nil
    }
    
    mid := (l + r) >> 1
    root := new(TreeNode)
    root.Val = res[mid]
    root.Left = sortedToBST(l, mid - 1)
    root.Right = sortedToBST(mid + 1, r)
    return root
}