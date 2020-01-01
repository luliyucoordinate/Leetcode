func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
    q1, q2, res := []int{}, []int{}, []int{}
    inOrder(root1, &q1)
    inOrder(root2, &q2)
    
    for len(q1) > 0 || len(q2) > 0 {
        if len(q1) == 0 || (len(q2) > 0 && q2[0] <= q1[0]) {
            res = append(res, q2[0])
            q2 = q2[1:]
        } else if len(q2) == 0 || (len(q1) > 0 && q1[0] < q2[0]) {
            res = append(res, q1[0])
            q1 = q1[1:]
        }
    }
    return res
}

func inOrder(root *TreeNode, q *[]int) {
    if root == nil {
        return 
    }
    inOrder(root.Left, q)
    *q = append(*q, root.Val)
    inOrder(root.Right, q)
}