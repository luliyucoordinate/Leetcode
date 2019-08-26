var removeZeroSumSublists = function(head) {
    var du = new ListNode(0), cur = du;
    du.next = head;
    var preSum = 0, m = new Map();
    while (cur != null) {
        preSum += cur.val;
        if (m.has(preSum)) {
            cur = m.get(preSum).next;
            var p = preSum + cur.val;
            while (p != preSum) {
                m.delete(p);
                cur = cur.next;
                p += cur.val;
            }
            m.get(preSum).next = cur.next;
        } else m.set(preSum, cur);
        cur = cur.next;
    }
    return du.next;
};