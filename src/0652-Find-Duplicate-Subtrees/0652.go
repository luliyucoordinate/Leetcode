var res []*TreeNode
var mem map[string]int
func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
    res = make([]*TreeNode, 0)
    mem = make(map[string]int)
    dfs(root)
    return res
}

func dfs(root *TreeNode) string {
    if root == nil {
        return ""
    }
    s := strconv.Itoa(root.Val) + "," + dfs(root.Left) + "," + dfs(root.Right)
    mem[s]++
    if mem[s] == 2 {
        res = append(res, root)
    }
    return s
}