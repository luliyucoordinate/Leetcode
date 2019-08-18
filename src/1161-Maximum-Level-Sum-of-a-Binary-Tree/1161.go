func maxLevelSum(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    q := []*TreeNode{root}
    res, maxSum, level := 0, 0, 0
    for len(q) > 0 {
        curSum, qLen := 0, len(q)
        for i := 0; i < qLen; i++ {
            node := q[0]
            q = q[1:]
            curSum += node.Val
            
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        level++
        if curSum > maxSum {
            maxSum, res = curSum, level
        }
    }
    return res
}