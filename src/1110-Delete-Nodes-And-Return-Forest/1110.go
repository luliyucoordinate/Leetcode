var res []*TreeNode
var delete_set map[int]bool

func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    delete_set = make(map[int]bool)
    for _, v := range to_delete {
        delete_set[v] = true
    }
    
    res = []*TreeNode{}
    preOrder(root, true)
    return res
}

func preOrder(root *TreeNode, n_root bool) *TreeNode {
    if root == nil {
        return nil
    }
    _, root_delete := delete_set[root.Val]
    if !root_delete && n_root {
        res = append(res, root)
    }
    
    root.Left = preOrder(root.Left, root_delete)
    root.Right = preOrder(root.Right, root_delete)
    if root_delete {
        return nil
    }
    return root
}