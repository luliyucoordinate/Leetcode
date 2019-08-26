func removeZeroSumSublists(head *ListNode) *ListNode {
    du := &ListNode{0, nil}
    cur := du
    du.Next = head
    preSum := 0
    m := make(map[int]*ListNode)
    
    for cur != nil {
        preSum += cur.Val
        if v, ok := m[preSum]; ok {
            cur = v.Next
            p := preSum + cur.Val
            for p != preSum {
                delete(m, p)
                cur = cur.Next
                p += cur.Val
            }
            m[preSum].Next = cur.Next
        } else {
            m[preSum] = cur
        }
        cur = cur.Next
    }
    return du.Next
}