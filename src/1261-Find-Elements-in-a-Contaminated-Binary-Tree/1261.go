type FindElements struct {
    data map[int]int
}


func Constructor(root *TreeNode) FindElements {
    res := FindElements{data:make(map[int]int)}
    root.Val, res.data[0] = 0, 1
    dfs(&res, root)
    return res
}

func dfs(this *FindElements, root* TreeNode) {
    if root.Left != nil {
        root.Left.Val = 2 * root.Val + 1
        this.data[root.Left.Val] = 1
        dfs(this, root.Left)
    } 
    if root.Right != nil {
        root.Right.Val = 2 * root.Val + 2
        this.data[root.Right.Val] = 1
        dfs(this, root.Right)
    }
}


func (this *FindElements) Find(target int) bool {
    if _, ok := this.data[target]; ok {
        return true
    }
    return false
}
