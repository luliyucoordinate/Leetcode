var removeZeroSumSublists = function(head) {
    var du = new ListNode(0), cur = du;
    du.next = head;
    var preSum = 0, m = {};
    while (cur != null) {
        preSum += cur.val;
        if (m[preSum]) {
            cur = m[preSum].next;
            var p = preSum + cur.val;
            while (p != preSum) {
                delete m[p];
                cur = cur.next;
                p += cur.val;
            }
            m[preSum].next = cur.next;
        } else m[preSum] = cur;
        cur = cur.next;
    }
    return du.next;
};