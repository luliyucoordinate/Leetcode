var getAllElements = function(root1, root2) {
    let inOrder = function(root, q) {
        if (root == null) return;
        inOrder(root.left, q);
        q.push(root.val);
        inOrder(root.right, q);
    }
    
    let q1 = [], q2 = [], res = [];
    inOrder(root1, q1);
    inOrder(root2, q2);
    
    while (q1.length || q2.length) {
        if (q1.length == 0 || (q2.length && q2[0] <= q1[0])) {
            res.push(q2.shift());
        } else if (q2.length == 0 || (q1.length && q1[0] < q2[0])) {
            res.push(q1.shift());
        }
    }
    return res;
};