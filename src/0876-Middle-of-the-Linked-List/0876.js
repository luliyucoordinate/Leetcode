var middleNode = function(head) {
    let fast = head, slow = head;
    while (fast.next != null && fast.next.next != null) {
        fast = fast.next.next;
        slow = slow.next;
    }

    if (fast.next != null && fast.next.next == null) return slow.next;
    return slow;
};