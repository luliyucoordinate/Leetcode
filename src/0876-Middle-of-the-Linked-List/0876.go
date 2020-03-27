func middleNode(head *ListNode) *ListNode {
    fast, slow := head, head
    for fast.Next != nil && fast.Next.Next != nil {
        fast = fast.Next.Next;
        slow = slow.Next;
    }

    if fast.Next != nil && fast.Next.Next == nil {
        return slow.Next
    }
    return slow
}