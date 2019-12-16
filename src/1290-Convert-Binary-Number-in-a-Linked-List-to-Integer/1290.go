func getDecimalValue(head *ListNode) int {
    res := 0
    for head != nil {
        res = (res << 1) | head.Val
        head = head.Next
    }
    return res
}